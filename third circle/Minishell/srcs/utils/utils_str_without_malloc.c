/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str_without_malloc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_len_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		i++;
	}
	return (i);
}

int	transform_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != 0 && s[i] != '=')
		i++;
	i++;
	while (s[i] != 0)
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
	{
		return ((char *)big);
	}
	if (len < 1)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && big[i + j])
		{
			j++;
			if (!little[j])
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
