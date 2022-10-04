/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:17:51 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_val(t_win *win)
{
	win->i = 0;
	win->tmp = NULL;
	win->res = NULL;
	win->tmp_old = NULL;
	win->tmp_home = NULL;
	win->copy = NULL;
}

void	ft_init_val_cmd(t_cmd *cmd)
{
	cmd->i = 0;
	cmd->j = 0;
	cmd->res = 0;
	cmd->cmd_nb = 0;
}

char	**ft_copy_env(char **new_env, char **old_env, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		new_env[i] = NULL;
		new_env[i] = ft_strdup(old_env[i]);
		if (!new_env[i])
			return (NULL);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}
