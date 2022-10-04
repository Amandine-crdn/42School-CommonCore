/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:11:44 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:11:46 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_second(int *stacka, int pb, int *stackb, int total)
{
	while (pb > 3)
	{
		if (ft_superior(stackb, pb) == 1)
			pb = ft_pa(stacka, stackb, pb, total - pb);
		else
			ft_check_max(stackb, pb);
	}
	ft_push_min_b(pb, stackb);
	while (pb > 0)
		pb = ft_pa(stacka, stackb, pb, total - pb);
}

int	ft_first_second(int *sort, int *stacka, int *stackb, int total)
{
	int	x;
	int	pb;
	int	i;
	int	chunk[100];

	x = 0;
	pb = 0;
	ft_calcul_block(chunk, total);
	while (total > 3)
	{
		i = 0;
		ft_sort_for_median(total, sort, stacka);
		while (i < chunk[x])
		{
			if (stacka[0] <= sort[chunk[x] - 1])
			{
				pb = ft_pb(stacka, stackb, pb);
				i = ft_range_stack_b(stacka, --total, i);
			}
			else
				ft_check_min(stacka, total, sort[chunk[x] - 1]);
		}
		x++;
	}
	return (pb);
}

int	ft_first(int *stacka, int total, int *stackb)
{
	int	*sort;
	int	pb;

	pb = 0;
	sort = malloc(sizeof(int) * total + 1);
	if (!sort)
		return (-1);
	pb = ft_first_second(sort, stacka, stackb, total);
	ft_free(sort);
	return (pb);
}

int	ft_start(int *stacka, int total)
{
	int	*stackb;
	int	pb;

	stackb = malloc(sizeof(int) * total + 1);
	pb = ft_first(stacka, total, stackb);
	if (pb == -1 || !stackb)
		return (-1);
	ft_push_min_a(total - pb, stacka);
	ft_second(stacka, pb, stackb, total);
	ft_free(stackb);
	return (0);
}
