/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:31:59 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_free_int_tab(char **tab, int size, char **tab2, int err)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < size)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
	i = 0;
	if (tab2)
	{
		while (tab2[i])
		{
			free(tab2[i]);
			i++;
		}
		free(tab2);
	}
	return (err);
}

static int	ft_modif_path(char **new_tab_line, t_win *win, int i, char **cmd)
{
	int		j;
	char	*word;

	j = 0;
	word = NULL;
	word = ft_strjoin(new_tab_line[0], "=");
	if (!word)
		return (ERROR_MALLOC);
	while (win->env[j] && ft_strnstr_check(win->env[j], \
			word, ft_strlen(word)) == NULL)
		j++;
	free(win->env[j]);
	win->env[j] = NULL;
	win->env[j] = ft_strdup(cmd[i]);
	if (!win->env[j])
		return (ft_free_str_int(word, ERROR_MALLOC));
	free(word);
	return (SUCCESS);
}

static int	ft_add_path(t_win *win, int j, char **cmd, int size)
{
	char	**temp;

	temp = NULL;
	temp = malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (ERROR_MALLOC);
	temp = ft_copy_env(temp, win->env, size);
	if (!temp)
		return (ft_free_tab_int(temp, ERROR_MALLOC));
	ft_free_tab(win->env, win->len_env);
	win->len_env++;
	win->env = NULL;
	win->env = malloc(sizeof(char *) * (win->len_env + 1));
	if (!win->env)
		return (ft_free_int_tab(temp, size, win->env, ERROR_MALLOC));
	win->env = ft_copy_env(win->env, temp, size);
	if (!win->env)
		return (ft_free_int_tab(temp, size, win->env, ERROR_MALLOC));
	win->env[size] = ft_strdup(cmd[j]);
	if (!win->env[size])
		return (ft_free_int_tab(temp, size, win->env, ERROR_MALLOC));
	win->env[win->len_env] = NULL;
	ft_free_tab(temp, size);
	return (SUCCESS);
}

static int	add_or_modif_path(t_win *win, char **newline, int i, char **cmd)
{
	char	*path;
	int		res;

	res = SUCCESS;
	path = NULL;
	path = check_path_exist(win->env, newline[0], win);
	if (path == NULL)
	{
		if (win->err_malloc == ERROR_MALLOC)
			return (ft_print_error_token(ERROR_MALLOC, "export"));
		else
		{
			res = ft_add_path(win, i, cmd, win->len_env);
			if (res == ERROR_MALLOC)
				return (ft_print_error_token(ERROR_MALLOC, "export"));
		}
	}
	else
	{
		res = ft_modif_path(newline, win, i, cmd);
		if (res == ERROR_MALLOC)
			ft_free_str_int(path, ERROR_MALLOC);
	}
	return (ft_free_str_int(path, res));
}

int	ft_export_env(t_win *win, char **cmd)
{
	int		i;
	int		res;
	char	**new_tab_line;

	res = SUCCESS;
	i = 1;
	while (cmd[i])
	{
		new_tab_line = NULL;
		new_tab_line = ft_split_path(cmd[i], '=');
		if (!new_tab_line)
			return (ft_print_error_token(ERROR_MALLOC, "export"));
		if (ft_strchr_export(cmd[i], '=') == SUCCESS \
			&& new_tab_line[1] && !new_tab_line[2])
		{
			res = add_or_modif_path(win, new_tab_line, i, cmd);
			if (res == ERROR_MALLOC)
				return (ft_free_tab_int(new_tab_line, ERROR_MALLOC));
		}
		i++;
		ft_free_tab(new_tab_line, 2);
	}
	g_exit_status = 0;
	return (res);
}
