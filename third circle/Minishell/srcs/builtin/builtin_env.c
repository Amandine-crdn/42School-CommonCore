/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_env(t_win *win, char **cmd)
{
	int	i;

	i = 0;
	if (!cmd[1])
	{
		while (i < win->len_env)
		{
			printf("%s\n", win->env[i]);
			i++;
		}
	}
	else
		return (ft_print_error_token(ERROR_SYNTAX, "env"));
	g_exit_status = 0;
	return (SUCCESS);
}
