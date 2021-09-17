#include "push_swap.h"

void	ft_range_stackB(int *stackB, int M)
{
	int	n;

	n = 0;
	while (n < M)
	{
		stackB[n] = stackB[n + 1];
		n++;
	}
}

void	ft_range_stackA(int *stackA, int pa)
{
	int n;

	n = pa;
	while (n > 0)
	{
		stackA[n] = stackA[n - 1];
		n--;
	}
}

void	ft_swap(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
	write(1, "SA\n", 3);
}

int ft_push_min(int total, int *A)
{
	if (A[0] > A[1] && A[1] < A[2] && A[0] > A[2])
        ft_rb(A, total);
	else if (A[0] < A[1] && A[1] > A[2] && A[0] > A[2])
		ft_rrb(A, total);
    else if (A[0] > A[1] && A[1] > A[2]) 
    {
        ft_swap(&A[0], &A[1]);
        ft_rrb(A, total);
    }
	 else if ((total == 2 && A[0] > A[1]) ||
        (A[1] < A[0] && A[1] < A[2]))
        ft_swap(&A[0], &A[1]);
    else if (A[0] < A[1] && A[1] > A[2]) 
    {
        ft_swap(&A[0], &A[1]);
        ft_rb(A, total);
    }
    printf("\n%d\n%d\n%d\n", A[0], A[1], A[2]);
    return (-1);
}