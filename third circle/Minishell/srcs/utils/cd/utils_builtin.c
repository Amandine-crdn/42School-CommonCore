/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:48:03 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 11:38:25 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	end(t_win *win, char *tmp_pwd)
{
	char	*res;

	res = NULL;
	res = ft_replace(win, tmp_pwd, "OLDPWD=", 0);
	if (res == NULL)
		return (ERROR_MALLOC);
	free(res);
	return (SUCCESS);
}

static int	ft_suite(t_win *win)
{
	char	*tmp_pwd;

	if (ft_creation(win) == ERROR)
		return (ft_print_error_token(ERROR_MALLOC, "cd"));
	tmp_pwd = NULL;
	tmp_pwd = ft_check_pwd(win);
	if (tmp_pwd == NULL)
		return (ERROR_MALLOC);
	if (end(win, tmp_pwd) == ERROR_MALLOC)
	{
		free(tmp_pwd);
		return (ERROR_MALLOC);
	}
	free(tmp_pwd);
	return (SUCCESS);
}

static int	ft_check_cd_suite(t_win *win, char **cmd)
{
	int	res;

	res = ft_return_value(win, cmd);
	if (res != 0)
		return (res);
	if (access(win->current_path, X_OK) == -1 || chdir(win->current_path) != 0)
	{
		ft_print_error_token(ERROR_SYNTAX, "cd");
		return (0);
	}
	res = ft_suite(win);
	if (win->value_cmd_path)
		free(win->value_cmd_path);
	if (win->tab)
		ft_free_tab(win->tab, win->memory);
	if (res == ERROR_MALLOC)
		return (ERROR_MALLOC);
	return (SUCCESS);
}

int	ft_check_cd(t_win *win, char **cmd)
{
	int		res;

	g_exit_status = 127;
	if (!cmd[1])
	{
		if (ft_home(win) == ERROR_MALLOC)
			return (ft_print_error_token(ERROR_MALLOC, "cd"));
		g_exit_status = 0;
		return (SUCCESS);
	}
	if (cmd[2])
		return (ft_print_error_token(ERROR_SYNTAX, "cd"));
	res = choice_current_path(cmd, win);
	if (res != SUCCESS)
		return (ft_print_error_token(ERROR_MALLOC, "cd"));
	g_exit_status = 0;
	res = ft_check_cd_suite(win, cmd);
	if (win->current_path)
		free(win->current_path);
	return (res);
}
