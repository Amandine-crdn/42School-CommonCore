/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_init_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 08:51:05 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_move_it(t_split *split)
{
	split->i++;
	split->temp++;
	if (split->s[split->temp] == '$')
		return (ERROR);
	return (SUCCESS);
}

static int	check_dollar2(t_split *split, t_win *win, char *check_str, int y)
{
	int	i;

	i = check_viability(split);
	if (i == ERROR)
		return (SUCCESS);
	if (i == ERROR_MALLOC)
		return (ERROR_MALLOC);
	check_str = ispathok_split(win->env, split->path, win);
	if (check_str != NULL)
	{
		while (check_str[y] != 0 && check_str[y] != '=')
			y++;
		while (check_str[++y])
			split->i++;
		if (split->s[split->temp] == '=')
		{
			while (split->s[split->temp] != 0)
			{
				if (ft_move_it(split) == ERROR)
					break ;
			}
		}
		return (ft_free_null_int(check_str, split->path, -99));
	}
	return (ft_free_null_int(check_str, split->path, SUCCESS));
}

int	check_symbol2(t_split *split, t_win *win)
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
				res = check_dollar2(split, win, NULL, 0);
		}
		else
			res = check_dollar2(split, win, NULL, 0);
		if (check_fixe(split) == -91)
			return (-91);
	}
	return (res);
}
