#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void    ft_free(char **area, int heigh)
{
    int i = 0;
    while(i < heigh)
    {
        free(area[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    FILE    *file;
    int     i, j, width, heigh, arg;
    char    **area, symb, c, back;
    float   x, y, radius, res;

    if (argc != 2)
    {
        write(2, "error arg\n", 10);
        return (1);
    }
    if (!(file = fopen(argv[1], "r")))
    {
        write(2, "error open\n", 11);
        return (1);
    }
    if (fscanf(file, "%d %d %c\n", &width, &heigh, &back) != 3)
    {
        fclose(file);
        write(2, "error scan\n", 11);
        return (1);
    }
    if (width <= 0 || width > 300 || heigh <= 0 || heigh > 300)
    {
        fclose(file);
        write(2, "error taille\n", 11);
        return (1);
    }
    //malloc
    area = malloc(sizeof(char *) * width + 1);
    if (!area)
    {
        ft_free(area, width);
        fclose(file);
        write(2, "error malloc\n", 12);
        return (1);
    }
    //background + malloc
    i = 0;
    while (i < width)
    {
        area[i] = malloc(sizeof(char) * heigh + 1);
        if (!area)
        {
            ft_free(area, i);
            fclose(file);
            write(2, "error malloc\n", 12);
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
    //exec + verif
    while ((arg = fscanf(file, "%c %f %f %f %c\n", &c, &x, &y, &radius, &symb)) == 5) 
    {
        if ((c != 'c' && c != 'C') || (radius <= 0.00000000))
        {
            ft_free(area, i);
            fclose(file);
            write(2, "error coco\n", 11);
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
                res = sqrtf(powf(a - y, 2) + powf(b - x, 2));
                if (res <= radius)
                    if ((radius - res < 1.00000000 && c == 'c') || c == 'C')
                        area[i][j] = symb;
                j++;
            }
            i++;
        }
    }

    //check arg sortie
    if (arg > 0 && argc != 5)
    {
        ft_free(area, i);
        fclose(file);
        write(2, "error arg sortie\n", 16);
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
    ft_free(area, i);
    fclose(file);
    return (0);
}