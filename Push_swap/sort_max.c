/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:11:17 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:11:19 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_sort(int *sort, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sort[i] = tab[i];
		i++;
	}
}

int	ft_sort_check_max(int *tab, int size)
{
	int	j;
	int	i;
	int	*sort;

	sort = malloc(sizeof(int) * size + 1);
	if (!sort)
		return (-1);
	ft_insert_sort(sort, tab, size);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sort[i] > sort[j])
				ft_swap(&sort[i], &sort[j]);
			j++;
		}
		i++;
	}
	i = sort[size - 1];
	ft_free(sort);
	return (i);
}

int	ft_search_startmax(int *stack, int pb, int max)
{
	int	i;

	i = 0;
	while (i < pb && stack[i] != max)
		i++;
	return (i);
}

int	ft_search_endmax(int *stack, int pb, int max)
{
	int	i;
	int	j;

	j = 0;
	i = pb - 1;
	while (i > 0 && stack[i] != max)
	{
		i--;
		j++;
	}
	return (j + 1);
}

void	ft_check_max(int *stack, int pb)
{
	int	max;
	int	next;
	int	next2;

	max = ft_sort_check_max(stack, pb);
	next = ft_search_startmax(stack, pb, max);
	next2 = ft_search_endmax(stack, pb, max);
	ft_choice_action_max(stack, next, next2, pb);
}
