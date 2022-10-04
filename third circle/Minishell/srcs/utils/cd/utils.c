/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:42:29 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:29:55 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*replace_copy(t_win *win, int y, int i, int p)
{
	char	*copy;

	copy = NULL;
	copy = malloc(sizeof(char) * (ft_strlen(win->env[i]) - y + 1));
	if (!copy)
	{
		win->err_malloc = 1;
		return (NULL);
	}
	while (win->env[i][y])
		copy[p++] = win->env[i][y++];
	copy[p] = 0;
	return (copy);
}

char	*ft_replace(t_win *win, char *current_path, char *var_path, int p)
{
	char	*copy;

	copy = NULL;
	win->i = 0;
	win->y = 0;
	while (win->env[win->i])
	{
		if (ft_strnstr(win->env[win->i], var_path, ft_strlen(var_path)))
		{
			while (win->env[win->i][win->y] != '=')
				win->y++;
			win->y++;
			copy = replace_copy(win, win->y, win->i, p);
			if (ft_modif_env(win, current_path, var_path, win->i) == NULL)
			{
				free(copy);
				return (NULL);
			}
		}
		win->i++;
	}
	win->err_malloc = 0;
	return (copy);
}

int	choice_current_path(char **cmd, t_win *win)
{
	win->current_path = NULL;
	if (cmd[1] && cmd[1][ft_strlen(cmd[1]) - 1] == '/')
	{
		win->current_path = ft_clean_cmd(cmd[1]);
		if (!win->current_path)
			return (ERROR);
		if (ft_strncmp(win->current_path, "~", 1) == 0)
			choice_suite(win);
	}
	else
	{
		win->current_path = ft_strdup(cmd[1]);
		if (!win->current_path)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_return_value(t_win *win, char **cmd)
{
	if (ft_strncmp(cmd[1], "-\0", 2) == 0)
		return (ft_return(win));
	else if (ft_strncmp(cmd[1], "/\0", 2) == 0)
		return (ft_racine(win));
	else if (ft_strncmp(cmd[1], "~\0", 2) == 0
		|| ft_strncmp(cmd[1], "~/\0", 3) == 0
		|| ft_strncmp(cmd[1], "--\0", 3) == 0)
		return (ft_home(win));
	return (0);
}

int	count_word(char *cmd)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (cmd[0] == '/' && cmd[i + 1] == 0)
		return (1);
	while (cmd && cmd[i])
	{
		if (cmd && i == 0 && cmd[i] == '/')
			i++;
		else if ((cmd[i] == '/') || ((i == ft_strlen(cmd) - 1)
				&& cmd[ft_strlen(cmd) - 1] != '/'))
			count++;
		if (cmd[i] == 0)
			break ;
		i++;
	}
	return (count);
}
