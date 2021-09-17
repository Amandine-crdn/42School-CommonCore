#include "push_swap.h"

int	ft_sort_int_tab(int *stackA, int argc)
{
	int j;
	int i;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stackA[i] == stackA[j])
			    return (-1);
			j++;
		}
		i++;
	}
    return (0);
}

int	ft_sort(int *stackA, int argc)
{
	int j;
	int i;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stackA[i] > stackA[j])
			    return (-1);
			j++;
		}
		i++;
	}
    return (0);
}


int ft_check_error(int *stackA, int argc)
{
    if (argc == 2 || argc == 1 || ft_sort(stackA, argc) == 0)
        exit(0);
    if (ft_sort_int_tab(stackA, argc) == -1)
    {
		write (1, "error\n", 6);
		exit(-1);
	}
    // if (ft_string())
    //     return (-1);
    return (0);
}