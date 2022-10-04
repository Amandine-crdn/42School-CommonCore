/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 11:38:14 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cd(t_win *win, char *cmd)
{
	if (ft_strncmp(cmd, "..\0", 3) == 0)
		return (ft_cd_pp(win, cmd));
	else if (ft_strncmp(cmd, ".\0", 2) == 0)
		return (SUCCESS);
	else
		return (ft_move(win, cmd, NULL, NULL));
}

int	ft_creation(t_win *win)
{
	char	*res;
	int		i;

	if (creation_malloc(win->current_path, win) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	if (creation_tab(win) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	res = NULL;
	if (win->current_path[0] == '/')
	{
		res = ft_replace(win, "/", "PWD=", 0);
		if (!res)
			return (ft_print_error_token(ERROR_MALLOC, "cd"));
	}
	i = 0;
	while (win->tab[i] && i < count_word(win->current_path))
	{
		if (ft_cd(win, win->tab[i]) == ERROR_MALLOC)
			return (ERROR_MALLOC);
		i++;
	}
	return (SUCCESS);
}
