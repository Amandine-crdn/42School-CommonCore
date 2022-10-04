/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:19:09 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_wordee(char **tab_word)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab_word[i] && tab_word[i][0] != '|')
	{
		if (ft_strncmp(tab_word[i], "<", 1) == 0
			|| ft_strncmp(tab_word[i], "<<", 2) == 0
			|| ft_strncmp(tab_word[i], ">", 1) == 0
			|| ft_strncmp(tab_word[i], ">>", 2) == 0)
			i++;
		else
			count++;
		i++;
	}
	return (count);
}

int	ft_check_type(char *s)
{
	if (s)
	{
		if (ft_strncmp(s, "<<", 2) == 0 && s[2] == 0)
			return (HEREDOC);
		else if (ft_strncmp(s, ">>", 2) == 0 && s[2] == 0)
			return (APPEND);
		else if (s[0] == '<' && s[1] == 0)
			return (INPUT);
		else if (s[0] == '>' && s[1] == 0)
			return (TRUNC);
	}
	return (ERROR);
}

void	ft_write_error_cmd(int res)
{
	(void)res;
	write(2, "Command not found\n", 18);
	g_exit_status = 127;
}

int	ft_count_pipeee(t_win *win)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (win->tab_line[i])
	{
		if (win->tab_line[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

int	ft_wait(int count_pipe, t_cmd *cmd_tab)
{
	int	i;
	int	pid;
	int	status;

	i = 0;
	pid = 0;
	status = 0;
	while (i <= count_pipe)
	{
		pid = waitpid(0, &status, 0);
		if (pid == -1)
			return (ERROR);
		else if (pid == cmd_tab->pid)
			attribute_exit_status(status);
		if (cmd_tab[i].outfile >= 0)
			close(cmd_tab[i].outfile);
		if (cmd_tab[i].infile >= 0)
			close(cmd_tab[i].infile);
		i++;
	}
	return (SUCCESS);
}
