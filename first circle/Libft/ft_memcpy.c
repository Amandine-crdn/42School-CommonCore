/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:21:41 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 11:19:07 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*str0;

	str = (char *)dst;
	str0 = (char *)src;
	i = 0;
	j = 0;
	if (!str && !str0)
		return (NULL);
	while (i < n)
	{
		str[i] = str0[j];
		i++;
		j++;
	}
	return (str);
}
