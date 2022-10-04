/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:11:23 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:11:24 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_start(int *stack, int total, int M)
{
	int	i;

	i = 0;
	while (stack[i] > M && i < total)
		i++;
	return (i);
}

int	ft_search_end(int *stack, int total, int M)
{
	int	i;
	int	j;

	j = 0;
	i = total - 1;
	while (stack[i] > M && i > 0)
	{
		i--;
		j++;
	}
	return (j);
}

void	ft_check_min(int *stack, int total, int M)
{
	int	next;
	int	next2;

	next = ft_search_start(stack, total, M);
	next2 = ft_search_end(stack, total, M);
	ft_choice_action_min(stack, next, next2, total);
}
