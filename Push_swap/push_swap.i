#include "push_swap.h"

int		ft_atoi(char *str)
{
	int i;
	long long int	res;
	int	neg;

	i = 0;
	neg = 1;
	res = 0;
	printf("---> %s\n", str);

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
	printf("nbr = %lld\n", res);

	if (res > INT_MAX)
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

void	ft_check(int *stackB, int total)
{
	int i = 0;
	int j = 1;
	int temp = 0;
	while (j < total)
	{
		if (stackB[i] > stackB[j])
			j++;
		else
		{
			temp = j;
			i = temp;
			j++;
		}
	}
	ft_action(stackB, i, total);
}

int		ft_superior(int *stackB, int total)
{
	int i;

	i = 1;
	while (i < total)
	{
		if (stackB[0] > stackB[i])
			i++;
		else
			break;
	}
	if (i != total)
		ft_check(stackB, total);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*stackA;
	int	*stackB;
	int pa;
	int total;

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


	ft_pb(stackA, stackB, total);
	while (pa < total)
	{
		if (ft_superior(stackB, total - pa) == 0)
		{
			pa = ft_pa(stackA, stackB, pa);
			ft_range_stackB(stackB, (total - pa));
		}
	}
	return (0);
}
