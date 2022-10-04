/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:12 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:12:13 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_atoi(char **argv, int argc)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1;
	while (i < argc - 1)
	{
		y = 0;
		while (argv[x][y] != 0 && i < argc - 1)
		{
			if (y == 0 && (argv[x][y] == '+' || argv[x][y] == '-'))
				y++;
			if (argv[x][y] == '+' || argv[x][y] == '-')
				return (-1);
			y++;
		}
		x++;
		i++;
	}
	if (y > 12)
		return (-1);
	return (0);
}

int	ft_sort_int_tab_error(int *stacka, int argc)
{
	int	j;
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stacka[i] == stacka[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_sort_error(int *stacka, int argc)
{
	int	j;
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stacka[i] > stacka[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_ascii(int argc, char **argv)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 1;
	while (i < argc - 1)
	{
		y = 0;
		while (argv[x][y] != 0 && i < argc - 1)
		{
			if ((argv[x][y] >= 48 && argv[x][y] <= 57) ||
		 	(argv[x][y] == 43) || (argv[x][y] == 45))
				y++;
			else
				return (-1);
		}
		x++;
		i++;
	}
	return (0);
}

int	ft_check_error(int *stacka, int argc, char **argv)
{
	if (ft_check_atoi(argv, argc) == -1)
	{
		write (2, "Error\n", 6);
		exit(-1);
	}
	if (ft_check_ascii(argc, argv) == -1)
	{
		write (2, "Error\n", 6);
		exit(-1);
	}
	if (ft_sort_int_tab_error(stacka, argc) == -1)
	{
		write (2, "Error\n", 6);
		exit(-1);
	}
	if (argc == 2 || argc == 1 || ft_sort_error(stacka, argc) == 0)
		exit(0);
	return (0);
}
