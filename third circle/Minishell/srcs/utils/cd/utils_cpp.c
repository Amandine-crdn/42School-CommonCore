/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cpp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_change_pwd(t_win *win, int i)
{
	if (ft_strnstr(win->env[i], "PWD=", 4))
	{
		free(win->env[i]);
		win->env[i] = NULL;
		win->env[i] = ft_strdup("PWD=/\0");
		if (!win->env[i])
			return (ft_print_error_token(ERROR_MALLOC, "cd"));
	}
	return (SUCCESS);
}

int	ft_cd_pp(t_win *win, char *cmd)
{
	int	compteur;
	int	i;

	compteur = 0;
	if (ft_strncmp(cmd, "..\0", 3) == 0)
	{
		compteur = ft_count_slash(win);
		if (compteur > 1)
		{
			if (ft_previous(win, compteur) == ERROR_MALLOC)
				return (ft_print_error_token(ERROR_MALLOC, "cd"));
		}
		else if (compteur == 1)
		{
			i = 0;
			while (win->env[i])
			{
				if (ft_change_pwd(win, i) == ERROR_MALLOC)
					return (ERROR_MALLOC);
				i++;
			}
		}
	}
	return (SUCCESS);
}
