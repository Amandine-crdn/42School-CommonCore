/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:47:11 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 10:45:49 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	size_t	i;

	if (!s)
		return (NULL);
	c = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = 0;
	return (c);
}
