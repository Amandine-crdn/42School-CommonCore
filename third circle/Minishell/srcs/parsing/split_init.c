/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:40:42 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_suite_cut(t_split *split, t_win *win, int res)
{
	while (split->s && split->s[split->temp] != 0)
	{
		res = check_symbol(split, win);
		if (res == ERROR_MALLOC)
			return (ERROR_MALLOC);
		if (check_return(split, 0) == SUCCESS && split->i != 0)
			break ;
		if (check_return(split, split->s[split->temp + 1]) == HEREDOC)
		{
			ft_increment(split, 3);
			break ;
		}
		if (check_return(split, 0) == SUCCESS)
		{
			ft_increment(split, 4);
			break ;
		}
		if (split->s[split->temp] == 0 || (split->fixe == 0 && \
			split->spe % 2 == 0 && (split->s[split->temp] == ' ')))
			break ;
		if (res != -91)
			split->new[split->j][split->i++] = split->s[split->temp++];
	}
	return (SUCCESS);
}

static int	cut_sentence_suite(t_split *split, t_win *win, int *len)
{
	int	res;

	res = 0;
	split->i = 0;
	split->fixe = 0;
	while (split->j < split->len_sentence && len[split->j] == 0)
		split->j++;
	if (split->j == split->len_sentence)
		return (SUCCESS);
	split->new[split->j] = NULL;
	split->new[split->j] = malloc(sizeof(char) * (len[split->j] + 1));
	if (!split->new[split->j])
		return (ERROR_MALLOC);
	if (ft_suite_cut(split, win, res) == ERROR_MALLOC)
		return (ft_free_null_int(split->new[split->j], NULL, ERROR_MALLOC));
	if (split->i != 0)
	{
		split->new[split->j][split->i] = 0;
		split->j++;
	}
	else
		free(split->new[split->j]);
	return (SUCCESS);
}

static char	**cut_sentence(t_split *split, t_win *win, int *len)
{
	int	res;

	res = 1;
	split->new = NULL;
	split->new = malloc(sizeof(char *) * (split->len_sentence + 1));
	if (!split->new)
		return (ft_free_str_null_tab(len, split->s, NULL));
	while (split->s && split->s[split->temp] != 0 && \
		split->j != split->len_sentence)
	{
		while (split->s && split->s[split->temp] != 0 && \
			(split->s[split->temp] == ' ' || split->s[split->temp] == '\t'))
			split->temp++;
		res = cut_sentence_suite(split, win, len);
		if (res != SUCCESS)
			return (NULL);
		while (split->s && split->s[split->temp] != 0 && \
			(split->s[split->temp] == ' ' || split->s[split->temp] == '\t'))
			split->temp++;
	}
	split->new[split->j] = NULL;
	return (split->new);
}

static void	ft_init_split(t_split *split)
{
	split->temp = 0;
	split->j = 0;
	split->spe = 0;
}

char	**ft_split_init(t_win *win, t_split *split)
{
	int	*len;

	len = NULL;
	split->s = NULL;
	split->s = ft_strdup(win->input);
	if (!split->s)
		return (NULL);
	ft_init_split(split);
	split->len_sentence = ft_count_sentence(split, win);
	if (split->len_sentence == ERROR_MALLOC)
		return (ft_free_str_null_tab(NULL, split->s, NULL));
	ft_init_split(split);
	len = ft_hav_tab_len(split, win);
	if (!len)
		return (ft_free_str_null_tab(NULL, split->s, NULL));
	ft_init_split(split);
	split->new = cut_sentence(split, win, len);
	if (!split->new)
		return (ft_free_str_null_tab(len, split->s, split->new));
	ft_free_str_null_tab(len, split->s, NULL);
	return (split->new);
}
