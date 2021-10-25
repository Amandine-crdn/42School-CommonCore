/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:11:31 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:11:33 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int				i;
	long long int	res;
	int				neg;

	i = 0;
	neg = 1;
	res = 0;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res * neg > INT_MAX || res * neg < INT_MIN)
	{
		write (2, "Error\n", 6);
		exit(-1);
	}
	return (res * neg);
}

void	ft_free(int *stack)
{
	free(stack);
	stack = NULL;
}

int	main(int argc, char **argv)
{
	int	*stacka;
	int	total;
	int	n;

	stacka = malloc(sizeof(int) * argc);
	if (!stacka)
		return (-1);
	total = argc - 1;
	n = 0;
	while (n < argc - 1)
	{
		stacka[n] = ft_atoi(argv[n + 1]);
		n++;
	}
	ft_check_error(stacka, argc, argv);
	if (total <= 3)
		return (ft_push_min(total, stacka));
	else
		n = ft_start(stacka, total);
	ft_free(stacka);
	return (n);
}
