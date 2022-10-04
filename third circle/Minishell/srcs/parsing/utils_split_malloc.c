/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 16:54:18 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_move_in_suite(t_split *split, int choice)
{
	if (choice == 0)
	{
		split->i++;
		split->temp++;
	}
	else if (choice == 1)
	{
		split->i += 2;
		split->temp += 2;
	}
}

static int	ft_suite(t_split *split, t_win *win, int res)
{
	while (split->s && split->s[split->temp] != 0)
	{
		res = check_symbol2(split, win);
		if (res == ERROR_MALLOC)
			return (ERROR_MALLOC);
		if (check_return(split, 0) == SUCCESS && split->i != 0)
			break ;
		if (check_return(split, split->s[split->temp + 1]) == HEREDOC)
		{
			ft_increment(split, 2);
			break ;
		}
		if (check_return(split, 0) == SUCCESS)
		{
			ft_increment(split, 1);
			break ;
		}
		if (split->s[split->temp] == 0 || (split->fixe == 0 \
			&& split->spe % 2 == 0 && (split->s[split->temp] == ' ')))
			break ;
		if (res != 91)
			ft_move_in_suite(split, 0);
	}
	return (SUCCESS);
}

int	ft_count_sentence(t_split *split, t_win *win)
{	
	while (split->s && split->s[split->temp] != 0)
	{
		while (split->s && split->s[split->temp] != 0
			&& (split->s[split->temp] == ' ' || split->s[split->temp] == '\t'))
			split->temp++;
		split->i = 0;
		split->fixe = 0;
		if (ft_suite(split, win, 0) != SUCCESS)
			return (ERROR_MALLOC);
		if (split->i != 0)
			split->j++;
		while (split->s && split->s[split->temp] != 0
			&& (split->s[split->temp] == ' ' || split->s[split->temp] == '\t'))
			split->temp++;
	}
	return (split->j);
}

static int	*ft_free_int_null(int *s)
{
	if (s)
		free(s);
	return (NULL);
}

int	*ft_hav_tab_len(t_split *split, t_win *win)
{
	int	*temp;

	temp = NULL;
	temp = malloc(sizeof(int) * split->len_sentence);
	if (!temp)
		return (NULL);
	while (split->s[split->temp])
	{
		while (split->s[split->temp] == ' ' || split->s[split->temp] == '\t')
			split->temp++;
		split->i = 0;
		split->fixe = 0;
		if (ft_suite(split, win, 0) != SUCCESS)
			return (ft_free_int_null(temp));
		if (split->i != 0)
		{
			temp[split->j] = split->i;
			split->j++;
		}
		while (split->s && split->s[split->temp] != 0
			&& (split->s[split->temp] == ' ' || split->s[split->temp] == '\t'))
			split->temp++;
	}
	return (temp);
}
