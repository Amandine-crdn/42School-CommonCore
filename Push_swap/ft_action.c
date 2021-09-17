#include "push_swap.h"

void	ft_action(int *stackB, int i, int total)
{
	int M;

	M = 0;
	if (total % 2 != 0)
		M = total + 1;
	else
		M = total;
	if (i <= M / 2)
	{
		while (i > 0)
		{
			ft_rb(stackB, total);
			i--;
		}
	}
	else
	{
		while (i < total)
		{
			ft_rrb(stackB, total);
			i++;
		}
	}
}

void	ft_rb(int *stackB, int M)
{
	int n;
	int temp;

	n = 0;
	temp = stackB[0];
	while (n < M - 1)
	{
		stackB[n] = stackB[n + 1];
		n++;
	}
	stackB[n] = temp;
	write(1, "RA\n", 3);
}

void	ft_rrb(int *stackB, int total)
{
	int n;
	int temp;

	n = total - 1;
	temp = stackB[n];
	while (n > 0)
	{
		stackB[n] = stackB[n - 1];
		n--;
	}
	stackB[0] = temp;	
	write(1, "RRB\n", 4);
}

int	ft_pa(int *stackA, int *stackB, int pa)
{

	write(1, "PA\n", 3);
	if (pa == 0)
		stackA[0] = stackB[0];
	else
	{
		ft_range_stackA(stackA, pa);
		stackA[0] = stackB[0];
	}
	return (pa + 1);
}

void	ft_pb(int *stackA, int *stackB, int	total)
{
	int i;

	write(1, "PB\n", 3);
	i = 0;
	while (i < total)
	{
		stackB[i] = stackA[i];
		i++;
	}
}
