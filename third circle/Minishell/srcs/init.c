/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:40:42 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_win(char **env, t_win *win)
{
	int	i;

	i = 0;
	win->nb_pipe = 0;
	win->len_tab = 0;
	win->len_env = 0;
	win->err_malloc = SUCCESS;
	win->input = NULL;
	win->env = NULL;
	win->tab_line = NULL;
	if (env[i] == NULL)
		return (ERROR);
	win->len_env = ft_len_env(env);
	win->env = malloc(sizeof(char *) * (win->len_env + 1));
	if (!win->env)
		return (ERROR_MALLOC);
	win->env = ft_copy_env(win->env, env, win->len_env);
	if (!win->env)
		return (ERROR_MALLOC);
	return (SUCCESS);
}

char	*ft_transform_path(char *s)
{
	int		y;
	int		i;
	char	*temp;

	y = 0;
	temp = NULL;
	temp = malloc(sizeof(char) * (transform_len(s) + 1));
	if (!temp)
		return (NULL);
	while (s[y] != 0 && s[y] != '=')
	{
		y++;
	}
	i = 0;
	while (s[++y])
	{
		temp[i++] = s[y];
	}
	temp[i] = 0;
	return (temp);
}

static void	ft_set_split_value(t_split *split)
{
	split->fixe = 0;
	split->spe = 0;
}

static void	ft_init_split(t_split *split, int a, int i, t_win *win)
{
	if (a == 0)
		ft_set_split_value(split);
	else if (a == 1)
	{
		if (win->input[i] == '"')
		{
			split->spe++;
			split->fixe = '"';
		}
		if (win->input[i] == '\'')
		{
			split->spe++;
			split->fixe = '\'';
		}
	}
	else
	{
		if (win->input[i] == split->fixe)
		{
			split->spe++;
			ft_init_split(split, 0, i, win);
		}
	}
}

int	ft_count_guillemet(t_win *win)
{
	t_split	split;
	int		i;

	i = 0;
	ft_init_split(&split, 0, i, win);
	while (win->input[i])
	{
		ft_init_split(&split, 1, i, win);
		if (split.fixe != 0)
		{
			while (win->input[i] && split.fixe != 0)
			{
				if (win->input[i] == split.fixe && (split.spe == 2))
					break ;
				i++;
				ft_init_split(&split, 3, i, win);
			}
		}
		if (win->input[i])
			i++;
	}	
	if (split.spe % 2 == 0)
		return (2);
	return (1);
}
