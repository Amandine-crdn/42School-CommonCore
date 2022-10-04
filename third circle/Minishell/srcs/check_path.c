/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:40:42 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_copy_path(t_win *win)
{
	int		j;
	char	**global_path;

	j = 0;
	global_path = NULL;
	while (win->env[j])
	{
		if (ft_strnstr(win->env[j], "PATH=", 5))
		{
			global_path = ft_split_path(&win->env[j][5], ':');
			if (!global_path)
				return (NULL);
		}
		j++;
	}
	return (global_path);
}

static char	*ft_build_access(char *tab_line, char **global_path, int i)
{
	char	*tmp;
	char	*curr_path;

	tmp = ft_strjoin(global_path[i], "/");
	if (!tmp)
		return (NULL);
	curr_path = ft_strjoin(tmp, tab_line);
	if (!curr_path)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (curr_path);
}

static char	*free_strs(char **big, char	*small, char *ret)
{
	int	i;

	i = 0;
	if (big)
	{
		while (big[i])
		{
			free(big[i]);
			i++;
		}
		free(big);
	}
	if (small)
		free(small);
	return (ret);
}

char	*find_path_char(char *tab_line, t_win *win, int i)
{
	char	*curr_path;
	char	**global_path;

	global_path = NULL;
	curr_path = NULL;
	if (access(tab_line, X_OK) == 0)
		return (tab_line);
	global_path = ft_copy_path(win);
	if (!global_path)
		return (NULL);
	while (global_path && global_path[i])
	{
		curr_path = ft_build_access(tab_line, global_path, i);
		if (curr_path == NULL)
			break ;
		if (access(curr_path, X_OK) != -1)
			return (free_strs(global_path, NULL, curr_path));
		i++;
		free(curr_path);
	}
	return (free_strs(global_path, NULL, NULL));
}

char	*ispathok_split(char **env, char *tab, t_win *win)
{
	int		i;
	char	*temp;
	int		y;

	i = 0;
	temp = NULL;
	while (env[i])
	{
		y = 0;
		while (env[i][y] != 0 && env[i][y] != '=')
		{
			if (env[i][y] != tab[y])
				break ;
			y++;
		}
		if (env[i][y] == '=' && tab[y] == 0)
		{
			temp = strdup(env[i]);
			if (!temp)
				return (ft_err_malloc(win, tab));
		}
		i++;
	}
	return (temp);
}
