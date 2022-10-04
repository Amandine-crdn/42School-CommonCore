/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/31 17:09:04 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	str_is_number(char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
	{
		str++;
		i++;
	}
	while (str && (*str >= '0' && *str <= '9'))
		str++;
	if (i <= 1 && *str == '\0')
		return (true);
	return (false);
}

static int	ft_exitcode(char *str)
{
	unsigned long long	exit_code;
	int					neg;

	exit_code = 0;
	neg = 1;
	if (ft_strlen(str) > 20 || str_is_number(str) == false)
		return (-2);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		exit_code = (exit_code * 10) + (*str - '0');
		if ((neg == -1 && (exit_code - 1) > LONG_MAX) || \
		(neg == 1 && (exit_code > LONG_MAX)))
			return (-2);
		str++;
	}
	if (*str != 0)
		return (-2);
	return ((neg * exit_code) % 256);
}

int	ft_exit(char **cmd)
{
	if (!cmd[1])
	{
		g_exit_status = 0;
		return (EXIT);
	}
	else
	{
		if (cmd[1])
		{
			g_exit_status = ft_exitcode(cmd[1]);
			if (g_exit_status == -2)
			{
				g_exit_status *= -1;
				printf("minishell: exit: argument numerique necessaire\n");
			}
			return (EXIT);
		}
		ft_print_error_token(ERROR, "exit");
		return (ERROR);
	}
}
