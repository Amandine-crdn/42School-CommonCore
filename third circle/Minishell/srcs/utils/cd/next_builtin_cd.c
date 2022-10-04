/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:31:59 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_modif_env(t_win *win, char *current_path, char *var_path, int i)
{
	free(win->env[i]);
	win->env[i] = NULL;
	win->env[i] = ft_strjoin(var_path, current_path);
	if (!win->env[i])
		win->err_malloc = 1;
	return (win->env[i]);
}

char	*ft_give_path(t_win *win, char *str, int i)
{
	int		p;
	int		y;
	char	*temp;

	p = 0;
	y = 0;
	temp = NULL;
	temp = malloc(sizeof(char) * (ft_strlen(win->env[i]) - ft_strlen(str) + 1));
	if (!temp)
		return (NULL);
	while (y != ft_strlen(str) && y < ft_strlen(win->env[i]))
		y++;
	while (y < ft_strlen(win->env[i]))
		temp[p++] = win->env[i][y++];
	temp[p] = 0;
	return (temp);
}

char	*ft_search_pwd(t_win *win)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (win->env[i])
	{
		if (ft_strnstr(win->env[i], "PWD=", 4))
		{
			tmp = ft_give_path(win, "PWD=", i);
			if (!tmp)
			{
				ft_print_error_token(ERROR_MALLOC, "cd");
				return (NULL);
			}
		}
		i++;
	}
	return (tmp);
}

int	ft_move(t_win *win, char *cmd, char *tmp, char *res)
{
	tmp = ft_search_pwd(win);
	if (tmp == NULL)
		return (ERROR_MALLOC);
	if (tmp[0] == '/' && tmp[1] != 0)
	{
		res = ft_strjoin(tmp, "/");
		if (!res)
			return (ft_free_str_int(tmp, ERROR_MALLOC));
	}
	else
	{
		res = ft_strdup(tmp);
		if (!res)
			return (ft_free_str_int(tmp, ERROR_MALLOC));
	}
	free(tmp);
	tmp = ft_strjoin(res, cmd);
	if (!tmp)
		return (ft_free_str_int(res, ERROR_MALLOC));
	free(res);
	res = ft_replace(win, tmp, "PWD=", 0);
	if (!res)
		return (ft_free_str_int(tmp, ERROR_MALLOC));
	return (ft_free_null_int(res, tmp, SUCCESS));
}
