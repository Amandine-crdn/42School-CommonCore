/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:02 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:12:03 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}

int	ft_superior(int *stackb, int nb_chunk)
{
	int	i;

	i = 1;
	while (i < nb_chunk)
	{
		if (stackb[0] > stackb[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_sort_int(int *tab, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				ft_swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_for_median(int new_value, int *sort, int *stacka)
{
	int	n;

	n = 0;
	while (n < new_value)
	{
		sort[n] = stacka[n];
		n++;
	}
	ft_sort_int(sort, new_value);
}
