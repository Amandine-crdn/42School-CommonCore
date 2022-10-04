/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_pwd(t_win *win)
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
			break ;
		}
		i++;
	}
	return (tmp);
}

char	*ft_check_oldpwd(t_win *win)
{
	int		i;
	char	*tmp_old;

	i = 0;
	tmp_old = NULL;
	while (win->env[i])
	{
		if (ft_strnstr(win->env[i], "OLDPWD=", 7))
		{
			tmp_old = ft_give_path(win, "OLDPWD=", i);
			if (!tmp_old)
				return (free_errormalloc_return_null(tmp_old));
		}
		i++;
	}
	return (tmp_old);
}

int	ft_return(t_win *win)
{
	ft_init_val(win);
	win->tmp_old = ft_check_oldpwd(win);
	if (!win->tmp_old)
		return (ft_print_error_token(ERROR_MALLOC, "cd"));
	if (chdir(win->tmp_old) != 0)
		return (ft_print_error_token(ERROR_FILE_DIRECTORY, "cd"));
	win->copy = ft_replace(win, win->tmp_old, "PWD=", 0);
	if (win->copy == NULL)
	{
		free(win->tmp_old);
		return (ft_print_error_token(ERROR_MALLOC, "cd"));
	}
	free(win->tmp_old);
	win->res = ft_replace(win, win->copy, "OLDPWD=", 0);
	if (win->res == NULL)
	{
		free(win->copy);
		return (ft_print_error_token(ERROR_MALLOC, "cd"));
	}
	ft_free_two_str(win->res, win->copy);
	return (SUCCESS);
}
