/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fonctions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:45:41 by acerdan           #+#    #+#             */
/*   Updated: 2021/07/20 12:25:31 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_intlen(int nb)
{
	int				i;
	int				negative;
	unsigned int	number;

	if (!nb)
		return (1);
	i = 0;
	if (nb < 0)
	{
		number = -nb;
		negative = 1;
	}
	else
	{
		number = nb;
		negative = 0;
	}
	while (number)
	{
		number = number / 10;
		i++;
	}
	return (i + negative);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!*s && !c)
		return ((char *)s);
	return (NULL);
}
