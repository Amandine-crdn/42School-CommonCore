/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_fill(t_win *win, char *word, int len, char **temp)
{
	int		y;
	int		z;

	y = 0;
	z = 0;
	while (y < win->len_env)
	{
		if (ft_strnstr_check(temp[z], word, len))
			z++;
		win->env[y++] = ft_strdup(temp[z++]);
		if (!win->env)
			return (ft_free_tab_int(temp, ERROR_MALLOC));
	}	
	win->env[y] = NULL;
	return (SUCCESS);
}

static int	ft_remplace(t_win *win, char *word, int len, int size)
{
	char	**temp;

	temp = NULL;
	temp = malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (ft_free_tab_int(temp, ERROR_MALLOC));
	temp = ft_copy_env(temp, win->env, size);
	if (!temp)
		return (ft_free_tab_int(temp, ERROR_MALLOC));
	ft_free_tab(win->env, win->len_env);
	win->len_env--;
	win->env = NULL;
	win->env = malloc(sizeof(char *) * (win->len_env + 1));
	if (!win->env)
		return (ft_free_tab_int(temp, ERROR_MALLOC));
	if (ft_fill(win, word, len, temp) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	return (ft_free_tab_int(temp, SUCCESS));
}

static int	ft_check_and_replace(t_win *win, char **cmd, int i, char *word)
{
	int	y;
	int	len;
	int	res;

	y = 0;
	res = SUCCESS;
	word = ft_strjoin(cmd[i], "=");
	if (!word)
		return (ft_free_str_int(word, ERROR_MALLOC));
	len = ft_strlen(word);
	while (y < win->len_env)
	{
		if (ft_strnstr_check(win->env[y], word, len))
		{
			res = ft_remplace(win, word, len, win->len_env);
			if (res == ERROR_MALLOC)
				return (ft_free_str_int(word, ERROR_MALLOC));
		}
		y++;
	}
	free(word);
	return (res);
}

int	ft_unset(t_win *win, char **cmd)
{
	int		i;
	char	*word;
	int		res;

	i = 1;
	res = SUCCESS;
	word = NULL;
	while (cmd[i])
	{
		res = ft_check_and_replace(win, cmd, i, word);
		if (res == ERROR_MALLOC)
		{
			free(word);
			ft_print_error_token(ERROR_MALLOC, "unset");
			return (ERROR_MALLOC);
		}
		i++;
		free(word);
	}
	g_exit_status = 0;
	return (res);
}
