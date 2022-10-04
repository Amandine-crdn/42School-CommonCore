/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/31 16:36:29 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_launch_builtin_or_bin(t_cmd *cmd_tab, t_win *win, int nbr_cmd)
{
	char	*path;
	int		res;

	res = 0;
	path = NULL;
	if (ft_check_own_builtin(cmd_tab[nbr_cmd].cmd_param[0]) == SUCCESS)
	{
		res = ft_parse_cmd(win, cmd_tab[nbr_cmd].cmd_param);
		if (res == EXIT || res == ERROR_MALLOC)
			return (EXIT);
	}
	else
	{
		path = find_path_char(cmd_tab[nbr_cmd].cmd_param[0], win, 0);
		if (path == NULL)
			return (ERROR_COMMAND);
		execve(path, cmd_tab[nbr_cmd].cmd_param, win->env);
	}
	return (ERROR);
}

static int	ft_launch_builtin(t_cmd *cmd_tab, t_win *win, int nbr_cmd)
{
	int	std_in;
	int	std_out;

	std_in = dup(0);
	std_out = dup(1);
	if (cmd_tab[nbr_cmd].infile >= 0)
		dup2(cmd_tab[nbr_cmd].infile, 0);
	if (cmd_tab[nbr_cmd].outfile >= 0)
		dup2(cmd_tab[nbr_cmd].outfile, 1);
	if (ft_parse_cmd(win, cmd_tab[nbr_cmd].cmd_param) == EXIT)
		return (EXIT);
	if (cmd_tab[nbr_cmd].infile >= 0)
	{
		dup2(std_in, 0);
		close(cmd_tab[nbr_cmd].infile);
	}
	if (cmd_tab[nbr_cmd].outfile >= 0)
	{
		dup2(std_out, 1);
		close(cmd_tab[nbr_cmd].outfile);
	}
	return (ERROR);
}

int	ft_exec_pipe(t_cmd *cmd_tab, t_win *win, int nbr_cmd, int nb_pipe)
{
	int	fd[2];
	int	res;

	if (pipe(fd) == -1)
		return (ft_print_error_token(ERROR_PIPE, "pipe"));
	cmd_tab[nbr_cmd].pid = fork();
	if (cmd_tab[nbr_cmd].pid < 0)
		return (ft_print_error_token(ERROR_FORK, "fork"));
	if (cmd_tab[nbr_cmd].pid == 0)
	{
		set_child_process(cmd_tab, nbr_cmd, nb_pipe, fd);
		res = ft_launch_builtin_or_bin(cmd_tab, win, nbr_cmd);
		if (res == EXIT)
			exit(g_exit_status);
		else if (res == ERROR_COMMAND)
			ft_write_error_cmd(res);
		ft_free_cmd_tab(cmd_tab);
		ft_free_tab(win->tab_line, win->len_tab);
		exit(g_exit_status);
	}
	else
		set_parent_process(cmd_tab, nbr_cmd, nb_pipe, fd);
	return (SUCCESS);
}

int	ft_launch_cmd(t_cmd *tab, t_win *win, int launch)
{
	int	nbr_cmd;

	nbr_cmd = 0;
	win->nb_pipe = ft_count_pipeee(win);
	if (tab[nbr_cmd].cmd_param && ft_check_own_builtin
		(tab[nbr_cmd].cmd_param[0]) == SUCCESS && win->nb_pipe == 0)
	{
		if (ft_launch_builtin(tab, win, nbr_cmd) == EXIT)
			return (EXIT);
		return (SUCCESS);
	}
	while (nbr_cmd <= win->nb_pipe)
	{
		if (tab[nbr_cmd].cmd_param != NULL)
		{
			launch = ft_exec_pipe(tab, win, nbr_cmd, win->nb_pipe);
			if (launch != SUCCESS)
				return (launch);
		}
		nbr_cmd++;
	}
	if (ft_wait(win->nb_pipe, tab) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
