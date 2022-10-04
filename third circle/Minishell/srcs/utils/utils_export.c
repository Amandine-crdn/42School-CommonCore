/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:40:42 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchr_export(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (SUCCESS);
		s++;
	}
	return (ERROR);
}

char	*ft_strnstr_check(char *big, char *little, size_t len)
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
				return ((char *)(big));
		}
		i++;
	}
	return (NULL);
}

char	*ft_err_malloc(t_win *win, char *word)
{
	win->err_malloc = ERROR_MALLOC;
	if (word == NULL)
		return (NULL);
	else
	{
		free(word);
		return (NULL);
	}
}

char	*check_path_exist(char **env, char *tab, t_win *win)
{
	int		i;
	char	*word;
	char	*temp;

	i = 0;
	word = NULL;
	temp = NULL;
	word = ft_strdup(tab);
	if (!word)
		return (ft_err_malloc(win, word));
	while (env[i] && ft_strnstr_check(env[i], word, ft_strlen(word)) == NULL)
		i++;
	if (env[i] != NULL)
	{
		temp = strdup(env[i]);
		if (!temp)
			return (ft_err_malloc(win, word));
	}	
	free(word);
	return (temp);
}
