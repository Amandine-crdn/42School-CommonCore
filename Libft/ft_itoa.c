/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:44:16 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 10:41:51 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nb;
	size_t	j;

	nb = n;
	j = ft_nbrlen(nb);
	c = (char *)malloc(sizeof(char) * j + 1);
	if (!c)
		return (NULL);
	c[j] = 0;
	if (n == 0)
		c[0] = '0';
	if (nb < 0)
	{
		c[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		c[--j] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (c);
}
