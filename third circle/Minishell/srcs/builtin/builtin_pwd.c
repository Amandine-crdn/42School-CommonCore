/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_print_pwd(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->len_env)
	{
		if (ft_strnstr(win->env[i], "PWD=", 4))
		{
			printf("%s\n", win->env[i] + 4);
			g_exit_status = 0;
			return (SUCCESS);
		}
		i++;
	}
	if (i == win->len_env)
	{
		ft_print_error_token(ERROR_SYNTAX, "pwd");
		return (ERROR);
	}
	g_exit_status = 0;
	return (SUCCESS);
}

int	ft_pwd(t_win *win, char **cmd)
{
	char	*path;

	path = check_path_exist(win->env, "PWD", win);
	if (path == NULL)
	{
		if (win->err_malloc == ERROR_MALLOC)
			return (ft_print_error_token(ERROR_MALLOC, "pwd"));
	}
	else
	{
		free(path);
		if (win->env && !cmd[1])
			return (ft_print_pwd(win));
		else if (!win->env)
		{
			ft_print_error_token(ERROR_SYNTAX, "pwd");
			return (ERROR);
		}
		else
			ft_print_error_token(ERROR_SYNTAX, "pwd");
	}
	g_exit_status = 0;
	return (SUCCESS);
}
