/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:34 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:12:36 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(int *stackb, int pb)
{
	int	n;
	int	temp;

	n = 0;
	temp = stackb[0];
	while (n < pb - 1)
	{
		stackb[n] = stackb[n + 1];
		n++;
	}
	stackb[n] = temp;
	write(1, "rb\n", 3);
}

void	ft_rrb(int *stackb, int pb)
{
	int	n;
	int	temp;

	n = pb - 1;
	temp = stackb[n];
	while (n > 0)
	{
		stackb[n] = stackb[n - 1];
		n--;
	}
	stackb[0] = temp;
	write(1, "rrb\n", 4);
}

int	ft_pb(int *stacka, int *stackb, int pb)
{
	int	i;

	write(1, "pb\n", 3);
	i = 0;
	if (pb != 0)
		ft_range_stack_a(stackb, pb);
	stackb[i] = stacka[i];
	return (pb + 1);
}

void	ft_range_stack_b2(int *stackb, int pb)
{
	int	n;

	n = 0;
	while (n < pb)
	{
		 stackb[n] = stackb[n + 1];
		n++;
	}
}

void	ft_swap_reel_b(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
	write(1, "sb\n", 3);
}
