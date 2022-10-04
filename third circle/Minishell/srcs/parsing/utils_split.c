/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:10:23 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 16:54:23 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_increment(t_split *split, int a)
{
	if (a == 2)
	{
		split->i += 2;
		split->temp += 2;
	}
	if (a == 1)
	{
		split->i++;
		split->temp++;
	}
	if (a == 3)
	{
		split->new[split->j][split->i++] = split->s[split->temp++];
		split->new[split->j][split->i++] = split->s[split->temp++];
	}
	if (a == 4)
		split->new[split->j][split->i++] = split->s[split->temp++];
}

int	check_return(t_split *split, char d)
{
	char	c;

	c = split->s[split->temp];
	if (split->spe % 2 == 0)
	{
		if ((c == '<' && d == '<') || (c == '>' && d == '>'))
			return (HEREDOC);
		if (d == 0 && (c == '|' || c == '>' || c == '<'))
			return (SUCCESS);
	}
	return (ERROR);
}

int	choice_road(t_split *split)
{
	if ((split->s[split->temp] == '$' && split->s[split->temp + 1] == '?') || \
		(split->s[split->temp] == '$' && split->s[split->temp + 1] == '?' && \
			split->fixe != 0 && split->s[split->temp + 2] == split->fixe))
		return (SUCCESS);
	else if (split->s[split->temp] == '$' && ((split->s[split->temp + 1] == 0) \
		|| (split->fixe != 0 && split->s[split->temp + 1] == split->fixe)))
		return (SUCCESS);
	return (ERROR);
}

int	initialize_fixe(t_split *split)
{
	if (split->s[split->temp] == '"' && split->fixe == 0)
		split->fixe = '"';
	else if (split->s[split->temp] == '\'' && split->fixe == 0)
		split->fixe = '\'';
	while (split->s[split->temp] == split->fixe)
	{
		split->temp++;
		split->spe++;
		if (split->spe % 2 == 0)
		{
			split->fixe = 0;
			split->spe = 0;
			return (-91);
		}
	}
	return (SUCCESS);
}

int	check_fixe(t_split *split)
{
	if (split->fixe != 0 && split->s[split->temp] == split->fixe)
	{
		split->temp++;
		split->spe++;
		split->fixe = 0;
		split->spe = 0;
		if (split->s[split->temp] == '"')
		{
			split->temp++;
			split->spe++;
			split->fixe = '"';
		}
		else if (split->s[split->temp] == '\'')
		{
			split->temp++;
			split->spe++;
			split->fixe = '\'';
		}
		else
			return (-91);
	}
	return (SUCCESS);
}
