/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:14:42 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 08:35:52 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s2;
	unsigned char	*s1;
	size_t			i;

	s2 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if (!s2 && !s1)
		return (NULL);
	i = 0;
	if (s2 > s1)
	{
		while (i < len)
		{
			s2[len - i - 1] = s1[len - i - 1];
			i++;
		}
	}
	else
		ft_memcpy(s2, s1, len);
	return (dst);
}
