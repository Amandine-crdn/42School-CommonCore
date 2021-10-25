/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:27 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:12:28 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(int *stacka, int *stackb, int pa, int total)
{
	write(1, "pa\n", 3);
	ft_range_stack_a(stacka, total);
	stacka[0] = stackb[0];
	ft_range_stack_b2(stackb, pa);
	return (pa - 1);
}

void	ft_ra(int *stacka, int total)
{
	int	n;
	int	temp;

	n = 0;
	temp = stacka[0];
	while (n < (total - 1))
	{
		stacka[n] = stacka[n + 1];
		n++;
	}
	stacka[n] = temp;
	write(1, "ra\n", 3);
}

void	ft_rra(int *stacka, int total)
{
	int	n;
	int	temp;

	n = total - 1;
	temp = stacka[n];
	while (n > 0)
	{
		stacka[n] = stacka[n - 1];
		n--;
	}
	stacka[0] = temp;
	write(1, "rra\n", 4);
}

void	ft_range_stack_a(int *stacka, int pa)
{
	int	n;

	n = pa;
	while (n > 0)
	{
		stacka[n] = stacka[n - 1];
		n--;
	}
}

void	ft_swap_reel_a(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
	write(1, "sa\n", 3);
}
