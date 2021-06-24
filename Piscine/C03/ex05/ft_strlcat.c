/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 07:38:24 by acerdan           #+#    #+#             */
/*   Updated: 2021/02/24 07:59:36 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0' && i < size - 1)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	if (ft_strlen(dest) > size)
		return (ft_strlen(src) + size);
	return (ft_strlen(dest) + ft_strlen(src));
}
