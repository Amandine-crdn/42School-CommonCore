/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_symbol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/01 16:53:45 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_path(t_split *split, int help)
{
	int		y;

	y = 0;
	split->path = NULL;
	split->path = malloc(sizeof(char) * (help + 1));
	if (!split->path)
		return (ERROR_MALLOC);
	while (split->s && split->s[split->temp] != 0 && help-- > 0 \
		&& split->s[split->temp] != split->fixe)
		split->path[y++] = split->s[split->temp++];
	split->path[y] = 0;
	return (SUCCESS);
}

int	check_viability(t_split *split)
{
	int	i;
	int	help;

	help = 0;
	while (split->s[split->temp] == '$')
		split->temp++;
	i = split->temp;
	while (split->s && split->s[i] != 0 && split->s[i] != ' ' \
		&& split->s[i] != split->fixe)
	{
		i++;
		help++;
		if (split->s[i] == '$' || split->s[i] == '=' || \
			(split->fixe != 0 && split->s[i] == split->fixe))
			break ;
	}
	if (help == 0)
		return (ERROR);
	if (create_path(split, help) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	return (i);
}

int	check_dollar_suite(t_split *split, char	*check_str)
{
	int		y;

	y = 0;
	while (check_str[y] != 0 && check_str[y] != '=')
		y++;
	while (check_str[++y])
		split->new[split->j][split->i++] = check_str[y];
	if (split->s[split->temp] == '=')
	{
		while (split->s[split->temp] != 0)
		{
			split->new[split->j][split->i++] = split->s[split->temp++];
			if (split->s[split->temp] == '$')
				break ;
		}
	}
	split->new[split->j][split->i] = 0;
	free(check_str);
	free(split->path);
	return (-99);
}

static int	check_dollar(t_split *split, t_win *win)
{
	char	*check_str;
	int		i;

	i = check_viability(split);
	if (i == ERROR)
		return (SUCCESS);
	if (i == ERROR_MALLOC)
		return (ERROR_MALLOC);
	check_str = NULL;
	check_str = ispathok_split(win->env, split->path, win);
	if (check_str != NULL)
		return (check_dollar_suite(split, check_str));
	return (ft_free_str_int(split->path, SUCCESS));
}

int	check_symbol(t_split *split, t_win *win)
{
	int	res;

	res = SUCCESS;
	if (initialize_fixe(split) == -91)
		return (-91);
	if (choice_road(split) == SUCCESS)
		return (SUCCESS);
	while (split->s[split->temp] == '$')
	{
		if (split->temp != 0)
		{
			if (split->s[split->temp - 1] == '\'')
				return (res);
			else
				res = check_dollar(split, win);
		}
		else
			res = check_dollar(split, win);
		if (check_fixe(split) == -91)
			return (-91);
	}	
	return (res);
}
