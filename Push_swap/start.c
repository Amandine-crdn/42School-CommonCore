#include "push_swap.h"

int ft_med100(int again, int x)
{
    int chunk[100];
    int i;
    i = 0;
    while (again % 2 != 0)
    {
        again +=1;
        i++;
    }
    chunk[x] = again / 2;  
    again = (again / 2) - i;
    printf("chunk[%d] = %d\n", x, chunk[x]);
    return (again);
    
}

int ft_med200(int again, int x)
{
    int chunk[100];
    int i;
    i = 0;
    while (again % 10 != 0)
	{
        again += 1;
        i++;
    }
    chunk[x] = again / 10;  
    again = again - chunk[x] - i;
    printf("chunk[%d] = %d\n", x, chunk[x]);           
    return (again);
}


int ft_med500(int again, int x)
{
    int chunk[100];
    int i;
    i = 0;
    while (again % 20 != 0)
	{
        again += 1;
        i++;
    }
    chunk[x] = again / 20;  
    again = again - chunk[x] - i;
    printf("chunk[%d] = %d\n", x, chunk[x]);           
    return (again);
}

int	ft_calcul_block(int total)
{
    int x;
    int again;
    
    x = 0;
    again = total;
	while (again > 3)
    {
        if (again < 100 && again > 3)
        {
            again = ft_med100(again, x);
            x++;
        }
        else if (again < 200)
        {
            again = ft_med200(again, x);
            x++;
        }
        else if (again < 500)
        {
            again = ft_med500(again, x);
            x++;
        }
    }
	return (x);
}

int		ft_atoi(char *str)
{
	int i;
	long long int	res;
	int	neg;

	i = 0;
	neg = 1;
	res = 0;

	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
    {
		write (1, "error\n", 6);
		exit(-1);
	}
	return (res * neg);
}

void	ft_add_value(int *stackA, int argc, char **argv)
{
	int	n;
	
	n = 0;
	while (n < argc - 1)
	{
		stackA[n] = ft_atoi(argv[n + 1]);
		n++;
	}
}

