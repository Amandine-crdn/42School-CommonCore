/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:05:22 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 12:05:24 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choice_action_max(int *stack, int next, int next2, int pb)
{
	int	i;

	i = 0;
	if (next > next2)
	{
		while (next2 > 0)
		{
			ft_rrb(stack, pb);
			next2--;
		}
	}
	else
	{
		while (next > 0)
		{
			ft_rb(stack, pb);
			next--;
			i++;
		}
	}
}

void	ft_choice_action_min(int *stack, int next, int next2, int total)
{
	if (next > next2)
	{
		while (next2 >= 0)
		{
			ft_rra(stack, total);
			next2--;
		}
	}
	else
	{
		while (next > 0)
		{
			ft_ra(stack, total);
			next--;
		}
	}
}

int	ft_range_stack_b(int *stackb, int pb, int i)
{
	int	n;

	n = 0;
	while (n < pb)
	{
		 stackb[n] = stackb[n + 1];
		n++;
	}
	return (i + 1);
}
