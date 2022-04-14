#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int     ft_check(int i, int j, float x, float y, float w, float h)
{
    int a = (float)i;
    int b = (float)j;
        if (a < y || b < x || a > y + h || b > x + w)
                return (0);
        if (a - y < 1.00000000 || b - x < 1.00000000 || y + h - a < 1.00000000 || x + w - b < 1.00000000)
                return (2);
        return (1);
}

int     main(int argc, char **argv)
{
    FILE    *file;
    char    **area, c, back, symb;
    int     i, j, heigh, width, arg;
    float   x, y, w, h;

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

    //gestion erreur
    while ((arg = fscanf(file, "%c %f %f %f %f %c\n", &c, &x, &y, &w, &h, &symb)) == 6)
    {
        if ((c != 'r' && c != 'R') || (w <= 0.00000000 || h <= 0.00000000))
        {
            write(2, "Ecrire r && R\n", 14);
            ft_free(area, width);
            fclose(file);
            return (1);
        }
        //check
        i = 0;
        while (i < width)
        {
            j = 0;
            while (j < heigh)
            {
                if (ft_check(i, j, x, y, w, h) && c == 'R')
                    area[i][j] = symb;
                if (ft_check(i, j, x, y, w, h) == 2&& c == 'r')
                    area[i][j] = symb;
                j++;
            }
            i++;
        }
    }
    printf("arg = %d\n", arg);
    //valeur de sortie de arg
    if (arg > 0 && arg != 6)
	{
		write(2, "Error sortie\n", 13);
		ft_free(area, width);
		fclose(file);
		return (1);
	}

    //dessin
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