/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:34:03 by acerdan           #+#    #+#             */
/*   Updated: 2021/05/27 10:46:08 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	is_charset(const char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*c;
	size_t	i;
	size_t	f;
	size_t	t;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_charset(s1[i], set))
		i++;
	f = ft_strlen(s1);
	while (f > i && is_charset(s1[f - 1], set))
		f--;
	c = (char *)malloc(sizeof(char) * (f - i + 1));
	if (!c)
		return (NULL);
	t = 0;
	while (i < f)
		c[t++] = s1[i++];
	c[t] = 0;
	return (c);
}
