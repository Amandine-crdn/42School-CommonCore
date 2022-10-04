/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir(char *filename, t_cmd *my_cmd)
{
	if (my_cmd->res == INPUT || my_cmd->res == HEREDOC)
	{
		if (my_cmd->infile >= 0)
			close(my_cmd->infile);
		my_cmd->infile = ft_open_files(filename, my_cmd->res);
		if (my_cmd->infile == ERROR)
			return (PB_OPEN);
	}
	else
	{
		if (my_cmd->outfile >= 0)
			close(my_cmd->outfile);
		my_cmd->outfile = ft_open_files(filename, my_cmd->res);
		if (my_cmd->outfile == ERROR)
			return (PB_OPEN);
	}
	return (SUCCESS);
}

static int	ft_define_cmd_param(t_win *win, t_cmd *cmd_tab, int i, int cmd_nb)
{
	if (ft_count_wordee(&win->tab_line[i]) == 0)
		cmd_tab[cmd_nb].cmd_param = NULL;
	else
	{
		cmd_tab[cmd_nb].cmd_param = malloc(sizeof(char *) \
			* (ft_count_wordee(&win->tab_line[i]) + 1));
		if (!cmd_tab[cmd_nb].cmd_param)
			return (ft_print_error_token(ERROR_MALLOC, "exec"));
		cmd_tab[cmd_nb].cmd_param[ft_count_wordee(&win->tab_line[i])] = NULL;
	}
	cmd_tab[cmd_nb].infile = -2;
	cmd_tab[cmd_nb].outfile = -2;
	return (SUCCESS);
}

static int	fill_param(char *str, t_cmd *cmd_tab)
{
	cmd_tab[cmd_tab->cmd_nb].cmd_param[cmd_tab->j] = NULL;
	cmd_tab[cmd_tab->cmd_nb].cmd_param[cmd_tab->j] = ft_strdup(str);
	if (!cmd_tab[cmd_tab->cmd_nb].cmd_param[cmd_tab->j])
		return (ft_print_error_token(ERROR_MALLOC, "exec"));
	cmd_tab->j++;
	return (SUCCESS);
}

static int	ft_end(t_win *win, t_cmd *tab, int i)
{
	if (i == 1)
	{
		if (tab[tab->cmd_nb].cmd_param != NULL)
			tab[tab->cmd_nb].cmd_param[tab->j] = NULL;
		if (win->tab_line[tab->i] && win->tab_line[tab->i][0] == '|')
			tab->i++;
		tab->cmd_nb++;
	}
	else if (i == 0)
	{
		tab[tab->cmd_nb].cmd_param = NULL;
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	ft_save_cmd(t_win *win, t_cmd *tab)
{
	ft_init_val_cmd(tab);
	while (win->tab_line[tab->i])
	{
		tab->j = 0;
		if (ft_define_cmd_param(win, tab, tab->i, tab->cmd_nb) != SUCCESS)
			return (ERROR_MALLOC);
		while (win->tab_line[tab->i] && win->tab_line[tab->i][0] != '|')
		{
			tab->res = ft_check_type(win->tab_line[tab->i]);
			if (tab->res != ERROR)
			{
				tab->i++;
				if (redir(win->tab_line[tab->i], &tab[tab->cmd_nb]) == PB_OPEN)
					return (ft_print_error_token(PB_OPEN, "open"));
			}
			else if (tab[tab->cmd_nb].cmd_param != NULL)
			{
				if (fill_param(win->tab_line[tab->i], tab) == ERROR_MALLOC)
					return (ERROR_MALLOC);
			}
			tab->i++;
		}
		ft_end(win, tab, 1);
	}
	return (ft_end(win, tab, 0));
}
