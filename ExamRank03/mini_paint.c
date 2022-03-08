#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ft_free(char **area, int heigh)
{
	int i = 0;
	while (i < heigh)
	{
		free(area[i]);
		i++;
	}
	return (1);
}

int ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	FILE 	*file;
	char 	**area, c, back, symb;
	int		i, j, heigh, width, arg;
	float	x, y, res, radius;

	//gestion des erreurs (nb arg, open, scan, taille)
	if (argc != 2)
		return (write(2, "error nb arg\n", 13) && 1);
	if (!(file = fopen(argv[1], "r")))
		return (ft_print_error());
	if (fscanf(file, "%d %d %c\n", &width, &heigh, &back) != 3)
		return (write(2, "error scan\n", 11) && fclose(file) && 1);
	if (width <= 0 || heigh <= 0 || width > 300 || heigh > 300)
		return (ft_print_error() && fclose(file));

	// malloc + attribution back
	area = malloc(sizeof(char *) * heigh + 1);
	if (!area)
		return (fclose(file) && 1);
	i = 0;
	while (i < heigh)
	{
		area[i] = malloc(sizeof(char) * width + 1);
		if (!area)
			return (fclose(file) && ft_free(area, i));
		j = 0;
		while (j < width)
		{
			area[i][j] = back;
			j++;
		}
		i++;
	}
	
	//gestion erreur
	while ((arg = fscanf(file, "%c %f %f %f %c\n", &c, &x, &y, &radius, &symb)) == 5)
	{
		if ((c != 'c' && c != 'C') || radius <= 0)
			return (ft_print_error() && ft_free(area, heigh) && fclose(file));
		//check
		i = 0;
		while (i < heigh)
		{
			j = 0;
			while (j < width)
			{
				res = sqrt(powf(i - y, 2) + powf(j - x, 2)); 
				if (res <= radius)
					if ((radius - res < 1 && c == 'c') || c == 'C')
						area[i][j] = symb;
				j++;
			}
			i++;
		}
	}
	
	//valeur de sortie de arg
	if (arg > 0 && arg != 5)
		return (ft_print_error() && ft_free(area, heigh) && fclose(file));
	
	//dessin
	i = 0;
	while (i < heigh)
	{
		j = 0;
		while (j < width)
		{
			write(1, &area[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (ft_free(area, heigh) && fclose(file) && 0);
}
