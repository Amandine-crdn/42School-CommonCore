/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:53:43 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 10:39:06 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i])
		i++;
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(dst) + ft_strlen(src));
}
