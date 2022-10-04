/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 13:43:26 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_own_builtin(char *cmd)
{
	if (cmd == NULL)
		return (NO_BUILTIN);
	if (ft_strncmp(cmd, "exit\0", 5) == 0 || ft_strncmp(cmd, "export\0", 7) == 0 \
		|| ft_strncmp(cmd, "env\0", 4) == 0 || ft_strncmp(cmd, "unset\0", 6) == 0 \
			|| ft_strncmp(cmd, "pwd\0", 4) == 0 || ft_strncmp(cmd, "cd\0", 3) \
				== 0 || ft_strncmp(cmd, "echo\0", 5) == 0)
		return (SUCCESS);
	return (NO_BUILTIN);
}

int	ft_check_var(t_win *win, char *name_with_egal, int size)
{
	int	i;

	i = 0;
	while (win->env[i])
	{
		if (ft_strnstr(win->env[i], name_with_egal, size))
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int	ft_verif_env_var(t_win *win)
{
	if (ft_check_var(win, "PATH=", 5) == ERROR)
	{
		write(2, "No PATH is set : No Minishell\n", 31);
		return (ERROR);
	}
	else if (ft_check_var(win, "PWD=", 4) == ERROR)
	{
		write(2, "No PWD is set : No Minishell\n", 30);
		return (ERROR);
	}
	else if (ft_check_var(win, "OLDPWD=", 7) == ERROR)
	{
		write(2, "No OLDPWD is set : No Minishell\n", 33);
		return (ERROR);
	}
	else if (ft_check_var(win, "HOME=", 5) == ERROR)
	{
		write(2, "No HOME is set : No Minishell\n", 31);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_parse_cmd(t_win *win, char **cmd)
{
	if (ft_strncmp(cmd[0], "exit\0", 5) == 0)
		return (ft_exit(cmd));
	else if (ft_strncmp(cmd[0], "export\0", 7) == 0)
		return (ft_export_env(win, cmd));
	else if (ft_strncmp(cmd[0], "env\0", 4) == 0)
		ft_print_env(win, cmd);
	else if (ft_strncmp(cmd[0], "unset\0", 6) == 0)
		return (ft_unset(win, cmd));
	else if (ft_strncmp(cmd[0], "pwd\0", 4) == 0)
		return (ft_pwd(win, cmd));
	else if (ft_strncmp(cmd[0], "cd\0", 2) == 0)
	{
		if (ft_verif_env_var(win) == ERROR)
			return (ERROR);
		return (ft_check_cd(win, cmd));
	}
	else if (ft_strncmp(cmd[0], "echo\0", 4) == 0)
		ft_echo(cmd, 1);
	return (0);
}
