/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:55:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/07 22:16:35 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define VIDE 0
#define RECTANGLE 2

int ft_check(int i, int j, float x, float y, float w, float h)
{
	if (i < y || i > y + h || j < x || j > x + w)
	{
		//	printf("VIDE\n");
			return (VIDE);
	}
	if (i - y < 1 || y + h - i < 1 || j - x < 1 || x + w - j < 1)
	{
		//  printf("RECTANGLE\n");
		return (RECTANGLE);
	}
	return (1);
}
int	ft_free(char **area, int height)
{
	int i;

	i = -1;
	while (++i < height)
		free(area[i]);
	free(area);
	return (1);
}

int	ft_error_print(void)
{
	write(2, "Error: Operation file corrupted\n", 32);
	return (1);
}

int	main (int argc, char **argv)
{
	FILE	*file;
	float	x, y, w, h;
	char	**area, c, back, symb;
	int		i, j, width, height, arg;

	if (argc != 2)
		return (write(2, "Error: argument\n", 16) && 1);
	if (!(file = fopen(argv[1], "r")))
		return (ft_error_print());
	if ((fscanf(file, "%d %d %c\n", &width, &height, &back)) != 3)
		return (ft_error_print() && fclose(file));
	if (width <= 0 || width > 300 || height <= 0 || height > 300)
		return (ft_error_print() && fclose(file));
	if (!(area = malloc(sizeof(char *) * (height + 1))))
		return (fclose(file) && 1);

	i = -1;
	while (++i < height)
	{
		area[i] = malloc(sizeof(char) * (width + 1));
		if (!(area[i]))
			return (ft_free(area, i) && fclose(file));
		j = -1;
		while (++j < width)
			area[i][j] = back;
	}
	
	while ((arg = fscanf(file, "%c %f %f %f %f %c\n", &c, &x, &y, &w, &h, &symb)) == 6)
	{
			printf("arg = %d\n", arg);
		//printf("\nx = %f\ny = %f\n\n", x, y);
		if ((c != 'r' && c != 'R') || (w <= 0 || h <= 0))
			return (ft_error_print() && ft_free(area, height) && fclose(file));
		i = -1;
		while (++i < height)
		{
			j = -1;
			while (++j < width)
			{
				if (ft_check(i, j, x, y, w, h) && c == 'R')
				{
				//	printf("\n-------1 INTERIEUR------\n");
					area[i][j] = symb;
				//	printf("\n\n[i][j] : [%d][%d] = %c\n\n", i, j, area[i][j]);
				}
				if (ft_check(i, j, x, y, w, h) == 2 && c == 'r')
				{
					area[i][j] = symb;
				//	printf("\n-------2 CONTOUR------\n");
				//	printf("\n\n[i][j] : [%d][%d] = %c\n\n", i, j, area[i][j]);
				}
			}
		}
	}
	printf("arg = %d\n", arg);
	if (arg > 0 && arg != 6)
		return (ft_error_print() && ft_free(area, height) && fclose(file));
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			write(1, &area[i][j], 1);
		write(1, "\n", 1);
	}
	return (ft_free(area, height) && fclose(file) && 0);
}
