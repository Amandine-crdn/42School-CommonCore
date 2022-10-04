/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:44 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:12:45 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_min(int total, int *a)
{
	if ((total == 2 && a[0] > a[1])
		|| (a[1] < a[0] && a[1] < a[2]))
		ft_swap_reel_a(&a[0], &a[1]);
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ft_ra(a, total);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		ft_rra(a, total);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		ft_swap_reel_a(&a[0], &a[1]);
		ft_rra(a, total);
	}
	else if (a[0] < a[1] && a[1] > a[2])
	{
		ft_swap_reel_a(&a[0], &a[1]);
		ft_ra(a, total);
	}
	ft_free(a);
	return (0);
}

void	ft_push_min_a(int total, int *a)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ft_ra(a, total);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		ft_rra(a, total);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		ft_swap_reel_a(&a[0], &a[1]);
		ft_rra(a, total);
	}
	else if ((total == 2 && a[0] > a[1])
		|| (a[1] < a[0] && a[1] < a[2]))
		ft_swap_reel_a(&a[0], &a[1]);
	else if (a[0] < a[1] && a[1] > a[2])
	{
		ft_swap_reel_a(&a[0], &a[1]);
		ft_ra(a, total);
	}
}

void	ft_push_min_b(int pb, int *b)
{
	if (pb == 2 && b[0] < b[1])
		ft_swap_reel_b(&b[0], &b[1]);
	else if (b[0] < b[1] && b[1] < b[2] && b[0] < b[2])
	{
		ft_swap_reel_b(&b[0], &b[1]);
		ft_rrb(b, pb);
	}
	else if (b[0] > b[1] && b[1] < b[2] && b[0] > b[2])
	{
		ft_rrb(b, pb);
		ft_swap_reel_b(&b[0], &b[1]);
	}
	else if (b[0] < b[1] && b[1] > b[2] && b[0] > b[2])
		ft_swap_reel_b(&b[0], &b[1]);
	else if (b[1] < b[0] && b[1] < b[2])
		ft_rrb(b, pb);
	else if (b[0] < b[1] && b[1] > b[2])
	{
		ft_rrb(b, pb);
		ft_rrb(b, pb);
	}
}
