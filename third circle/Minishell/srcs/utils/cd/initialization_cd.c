/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_cd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 09:51:32 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_clean_cmd(char *cmd)
{
	int		i;
	char	*clean_cmd;

	i = 0;
	clean_cmd = NULL;
	if (cmd && cmd[ft_strlen(cmd) - 1] == '/')
	{	
		clean_cmd = malloc(sizeof(char) * ft_strlen(cmd));
		if (!clean_cmd)
			return (NULL);
		while (cmd && i < ft_strlen(cmd) - 1)
		{
			clean_cmd[i] = cmd[i];
			i++;
		}
		clean_cmd[i] = 0;
	}
	return (clean_cmd);
}

static int	ft_initialization(t_win *win, char *cmd)
{
	win->tmp_home = NULL;
	win->tmp_home = ft_check_home(win);
	if (!win->tmp_home)
		return (ERROR_MALLOC);
	win->res = NULL;
	win->res = malloc(sizeof(char) * ((ft_strlen(win->tmp_home) \
				* count_tild(cmd)) + ft_strlen(cmd) - count_tild(cmd) + 1));
	if (!win->res)
	{
		free(win->tmp_home);
		return (ERROR_MALLOC);
	}
	return (SUCCESS);
}

static char	*transform_tild(t_win *win, char *cmd, int i, int j)
{
	int	z;
	int	ret;

	ret = ft_initialization(win, cmd);
	if (ret == ERROR_MALLOC)
		return (NULL);
	z = 0;
	while (cmd[i])
	{
		if (cmd[i] == '~')
		{
			while (win->tmp_home[z])
				win->res[j++] = win->tmp_home[z++];
			i++;
			if (cmd[i] == 0)
				break ;
		}
		win->res[j++] = cmd[i++];
	}
	win->res[j] = 0;
	free(win->tmp_home);
	return (win->res);
}

int	choice_suite(t_win *win)
{
	win->copy = NULL;
	win->copy = ft_strdup(win->res);
	if (!win->copy)
	{
		free(win->res);
		return (ERROR_MALLOC);
	}
	win->res = transform_tild(win, win->copy, 0, 0);
	if (!win->res)
	{
		free(win->copy);
		return (ERROR_MALLOC);
	}
	free(win->copy);
	return (SUCCESS);
}
