/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/12/13 17:03:55 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

int	ft_init_prgm(int ac, char **env, t_win *win)
{
	int	res;

	g_exit_status = 127;
	if (ac != 1)
		return (ft_print_error_token(END_MINISHELL, "arg"));
	res = ft_init_win(env, win);
	if (res == ERROR_MALLOC)
	{
		ft_free_tab(win->env, win->len_env);
		return (ft_print_error_token(ERROR_MALLOC, "exit"));
	}
	else if (res == ERROR)
		return (ft_print_error_token(ERROR, "exit"));
	return (SUCCESS);
}

static int	ft_super_init(t_win *win, char **argv)
{
	(void)argv;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	win->input = readline(">>>");
	if (!win->input)
		return (ERROR);
	if (win->input)
		add_history(win->input);
	return (SUCCESS);
}

static int	ft_fill_tab(t_win *win, t_cmd *cmd_tab)
{
	int		res;
	int		res2;

	cmd_tab[ft_count_pipeee(win) + 1].cmd_param = NULL;
	ft_doll_int(win->tab_line);
	res = ft_save_cmd(win, cmd_tab);
	if (res == ERROR_MALLOC)
	{
		ft_free_double_tab(cmd_tab, win->tab_line, win->len_tab, 1);
		return (ERROR_MALLOC);
	}
	else if (res != PB_OPEN)
	{
		res2 = ft_launch_cmd(cmd_tab, win, 0);
		if (res2 == EXIT)
		{
			ft_free_double_tab(cmd_tab, win->tab_line, win->len_tab, 0);
			return (EXIT);
		}
	}
	return (SUCCESS);
}

static int	ft_main_process(t_win *win, t_split *split, t_cmd *cmd_tab)
{
	win->tab_line = ft_split_init(win, split);
	if (!win->tab_line)
	{
		ft_print_error_token(ERROR_MALLOC_MAIN, "malloc");
		return (ERROR_MALLOC);
	}
	win->len_tab = split->len_sentence;
	if (win->tab_line[0] != NULL)
	{
		cmd_tab = NULL;
		cmd_tab = malloc(sizeof(t_cmd) * (ft_count_pipeee(win) + 2));
		if (cmd_tab == NULL)
		{
			ft_print_error_token(ERROR_MALLOC_MAIN, "malloc");
			return (ERROR_MALLOC);
		}
		if (ft_fill_tab(win, cmd_tab) != SUCCESS)
			return (ERROR_MALLOC);
		if (cmd_tab)
			ft_free_cmd_tab(cmd_tab);
	}
	return (SUCCESS);
}

int	main(int ac, char **argv, char **env)
{
	t_win	win;
	t_split	split;
	t_cmd	*cmd_tab;

	cmd_tab = NULL;
	if (ft_init_prgm(ac, env, &win) != SUCCESS)
		return (ERROR);
	while (1)
	{
		if (ft_super_init(&win, argv) == ERROR)
			break ;
		if (ft_count_guillemet(&win) % 2 != 0)
			printf("Undefined behaviour\n");
		else
		{
			if (ft_main_process(&win, &split, cmd_tab) != SUCCESS)
			{
				ft_free_tab(win.env, win.len_env);
				exit(g_exit_status);
			}
			ft_free_tab(win.tab_line, win.len_tab);
		}
	}
	ft_free_tab(win.env, win.len_env);
	return (SUCCESS);
}
