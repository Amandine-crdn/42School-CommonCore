/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_pwd(t_win *win)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (win->env[i])
	{
		if (ft_strnstr(win->env[i], "PWD=", 4))
		{
			tmp = ft_give_path(win, "PWD=", i);
			if (!tmp)
				return (free_errormalloc_return_null(tmp));
		}
		i++;
	}
	return (tmp);
}

char	*ft_check_home(t_win *win)
{
	int		i;
	char	*tmp_home;

	i = 0;
	tmp_home = NULL;
	while (win->env[i])
	{
		if (ft_strnstr(win->env[i], "HOME=", 5))
		{
			tmp_home = ft_give_path(win, "HOME=", i);
			if (!tmp_home)
				return (NULL);
		}
		i++;
	}
	return (tmp_home);
}

int	ft_home(t_win *win)
{
	ft_init_val(win);
	win->tmp_home = ft_check_home(win);
	if (!win->tmp_home)
		return (ERROR_MALLOC);
	if (chdir(win->tmp_home) != 0)
		return (ft_free_str_int(win->tmp_home, ERROR));
	win->tmp = check_pwd(win);
	if (!win->tmp)
		ft_free_null_int(win->tmp, win->tmp_home, ERROR_MALLOC);
	win->res = ft_replace(win, win->tmp, "OLDPWD=", 0);
	if (win->res == NULL)
	{
		ft_free_two_str(win->tmp, win->tmp_home);
		return (ft_free_str_int(win->res, ERROR_MALLOC));
	}
	free(win->res);
	win->res = ft_replace(win, win->tmp_home, "PWD=", 0);
	if (win->res == NULL)
	{
		ft_free_two_str(win->tmp, win->tmp_home);
		return (ft_free_str_int(win->res, ERROR_MALLOC));
	}
	ft_free_two_str(win->tmp, win->tmp_home);
	return (ft_free_str_int(win->res, SUCCESS));
}
