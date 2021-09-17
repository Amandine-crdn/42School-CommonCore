#include "push_swap.h"

void    ft_go(int total)
{
    int chunk;
    int	*sort;

    sort = (int *)malloc(sizeof(int) * total);
    chunk = ft_calcul_block(total);
    printf("block = %d\n", chunk);
    

}

int     ft_calcul_median(int total, int *stackA)
{
    if (total <= 3)
        return (ft_push_min(total, stackA));
    else
        ft_go(total);
    return (0);
}

int main(int argc, char **argv)
{
	int	*stackA;
	int	*stackB;
	int pa;
	int total;
    int median;
  
	stackA = (int *)malloc(sizeof(int) * argc);
	if (!stackA)
		return (-1);
	stackB = (int *)malloc(sizeof(int) * argc);
	if (!stackB)
		return (-1);
	total = argc - 1;
    pa = 0;
	ft_add_value(stackA, argc, argv);
	ft_check_error(stackA, argc);
    median = ft_calcul_median(total, stackA);
    if (median == -1)
        return (0);
    return (0);
}