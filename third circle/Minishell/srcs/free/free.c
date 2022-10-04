/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:50:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_str_int(char *s, int err)
{
	free(s);
	if (err == ERROR_MALLOC)
		printf("Malloc error\n");
	return (err);
}

int	ft_free_null_int(char *s, char *s2, int err)
{
	if (s)
		free(s);
	if (s2)
		free(s2);
	if (err == ERROR_MALLOC)
		return (ERROR_MALLOC);
	else
		return (SUCCESS);
}

int	ft_free_tab_int(char **big, int err)
{
	int	i;

	i = 0;
	if (big)
	{
		while (big[i])
		{
			free(big[i]);
			i++;
		}
		free(big);
	}
	return (err);
}
