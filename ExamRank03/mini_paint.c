#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	ft_free(char **area, int heigh)
{
	int i = 0;
	while (i < heigh)
	{
		free(area[i]);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	char	**area, c, back, symb;
	int		i, j, heigh, width, arg;
	float	x, y, res, radius;
	
	if (argc != 2)
	{
		write(2, "error nb arg\n", 13);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(2, "error open\n", 11);
		return (1);
	}
	if (fscanf(file, "%d %d %c\n", &width, &heigh, &back) != 3)
	{
		write(2, "error scan 1er ligne\n",21);
		fclose(file);
		return (1);
	}
	if (heigh <= 0 || heigh > 300 || width <= 0 || width > 300)
	{
		write(2, "error dimension\n", 11);
		fclose(file);
		return (1);
	}
	
	//malloc
	area = malloc(sizeof(char *) * width + 1);
	if (!area)
	{
		write(2, "error malloc\n", 12);
		ft_free(area, width);
		fclose(file);
		return (1);
	}
	//background
	i = 0;
	while (i < width)
	{
		area[i] = malloc(sizeof(char) * heigh + 1);
		if (!area)
		{
			write(2, "error malloc\n", 12);
			ft_free(area, i);
			fclose(file);
			return (1);
		}
		j = 0;
		while (j < heigh)
		{
			area[i][j] = back;
			j++;
		}
		i++;
	}
	//check
	while ((arg = fscanf(file, "%c %f %f %f %c\n", &c, &x, &y, &radius, &symb)) == 5)
	{
		if ((c != 'c' && c != 'C') || radius <= 0)
		{
			write(2, "Ecrire r && R\n", 14);
			ft_free(area, width);
			fclose(file);
			return (1);
		}
		i = 0;
		while (i < width)
		{
			j = 0;
			while (j < heigh)
			{
				int a = (float)i;
				int b = (float)j;
				res = sqrt(powf(a - y, 2) + powf(b - x, 2));
				if (res <= radius)
					if ((radius - res < 1  && c == 'c') || c == 'C')
						area[i][j] = symb;
				j++;
			}
			i++;
		}

	}
	printf("arg = %d\n", arg);
	if (arg > 0 && arg != 5)
	{
		write(2, "Error sortie\n", 13);
		ft_free(area, width);
		fclose(file);
		return (1);
	}

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < heigh)
		{
			write(1, &area[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_free(area, width);
	fclose(file);
	return (0);
}
