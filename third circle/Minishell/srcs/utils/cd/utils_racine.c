/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_racine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 10:31:59 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_modif_pwd(t_win *win, int i)
{
	free(win->env[i]);
	win->env[i] = NULL;
	win->env[i] = ft_strjoin("PWD=", "/");
	if (!win->env[i])
		ft_free_str_int(win->tmp, ERROR_MALLOC);
	return (SUCCESS);
}

int	ft_racine(t_win *win)
{
	int	i;

	i = 0;
	ft_init_val(win);
	while (win->env[i])
	{
		if (ft_strnstr(win->env[i], "PWD=", 4))
		{
			win->tmp = ft_give_path(win, "PWD=", i);
			if (!win->tmp)
				return (ERROR_MALLOC);
			if (ft_modif_pwd(win, i) == ERROR_MALLOC)
				return (ERROR_MALLOC);
		}
		i++;
	}
	win->err_malloc = 1;
	win->res = ft_replace(win, "OLDPWD=", win->tmp, 0);
	if (win->err_malloc == 1)
		return (ERROR_MALLOC);
	free(win->res);
	if (chdir("/") != 0)
		ft_print_error_token(ERROR, "cd");
	return (ft_free_str_int(win->tmp, SUCCESS));
}
