/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:18 by acerdan           #+#    #+#             */
/*   Updated: 2021/09/24 08:12:19 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_value_chunk(int again, int div)
{
	int	i;

	i = 0;
	while (again % div != 0)
	{
		again += 1;
		i++;
	}
	return (again / div);
}

int	ft_modif_chunk(int x, int *chunk, int div)
{
	int	i;

	i = 0;
	while (chunk[x] % div != 0)
	{
		chunk[x] += 1;
		i++;
	}
	return (i);
}

int	ft_choice_nbr(int again)
{
	int	nb;

	nb = 0;
	if (again <= 50)
		nb = 10;
	else if (again < 150)
		nb = 20;
	else if (again < 300)
		nb = 35;
	else if (again <= 500)
		nb = 47;
	else if (again > 500)
		nb = 60;
	return (nb);
}

int	ft_calcul_block(int *chunk, int total)
{
	int	x;
	int	again;
	int	nb;

	nb = 0;
	x = 0;
	again = total;
	nb = ft_choice_nbr(again);
	while (again > 3)
	{
		chunk[x] = ft_value_chunk(again, 2);
		while (chunk[x] >= nb)
		{
			ft_modif_chunk(x, chunk, 2);
			chunk[x] = chunk[x] / 2;
		}
		again = again - chunk[x];
		x++;
	}
	return (nb);
}
