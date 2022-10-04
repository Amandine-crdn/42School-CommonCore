/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 11:32:54 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(char *cmd, t_win *win)
{
	win->a = 0;
	win->i = 0;
	win->j = 0;
	win->memory = 0;
	win->len = ft_strlen(cmd);
}

static void	crea_suite(char *cmd, t_win *win)
{
	if (win->i == 0 && cmd[0] == '/' && cmd[1] != 0)
	{
		win->i++;
		win->len -= 1;
		win->a = 1;
	}
	else if (cmd[win->i] != '/')
	{
		win->i++;
		win->j++;
	}
}

int	creation_malloc(char *cmd, t_win *win)
{
	win->value_cmd_path = NULL;
	win->value_cmd_path = malloc(sizeof(int) * (count_word(cmd)));
	if (!win->value_cmd_path)
		return (ERROR_MALLOC);
	init_data(cmd, win);
	while (cmd && cmd[win->i])
	{
		crea_suite(cmd, win);
		if ((cmd[win->i] == '/') || \
			((win->i == win->len) && cmd[win->len] != '/'))
		{
			if (win->i == win->len && cmd[win->len] != '/' && win->a == 1)
				win->j++;
			win->value_cmd_path[win->memory] = win->j;
			win->memory++;
			win->j = 0;
			if (cmd[win->i] == 0)
				break ;
			win->i++;
		}
	}
	return (SUCCESS);
}

int	value_i(int i, t_win *win)
{
	int	j;

	if (i == 0 && win->current_path[i] == '/' && win->current_path[1] != 0)
		i++;
	win->tab[win->size] = NULL;
	win->tab[win->size] = malloc(sizeof(char) * \
		(win->value_cmd_path[win->size] + 1));
	if (!win->tab[win->size])
	{
		ft_free_tab(win->tab, win->size);
		return (ERROR_MALLOC);
	}
	j = 0;
	while (win->current_path[i] && win->current_path[i] != '/' && \
		j < win->value_cmd_path[win->size])
		win->tab[win->size][j++] = win->current_path[i++];
	win->tab[win->size++][j] = 0;
	return (i);
}

int	creation_tab(t_win *win)
{
	int	i;

	i = 0;
	win->size = 0;
	win->tab = NULL;
	win->tab = malloc(sizeof(char *) * ((win->memory + 1) + 1));
	if (!win->tab)
		return (ERROR_MALLOC);
	while (win->current_path && win->current_path[i])
	{
		i = value_i(i, win);
		if (i == ERROR_MALLOC)
			return (i);
		if (win->current_path[i] == 0)
			break ;
		i++;
	}
	win->tab[win->size] = NULL;
	return (SUCCESS);
}
