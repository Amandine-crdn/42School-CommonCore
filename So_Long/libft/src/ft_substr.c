/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:12:54 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 10:46:22 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start])
		{
			c[i] = (char)s[start];
			i++;
			start++;
		}
		c[i] = '\0';
	}
	else
		c[0] = 0;
	return (c);
}
