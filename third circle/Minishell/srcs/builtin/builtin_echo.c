/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 13:42:36 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
		{
			i++;
			while (s[i])
			{
				if (s[i] == 'n')
					i++;
				else
					return (i);
			}
		}
		else
			return (i);
	}
	return (i);
}

static void	ft_print_multiple_param(char **cmd, int i)
{
	int	space;

	space = 0;
	while (cmd[i])
	{
		if (i == 1)
		{
			if (ft_isn(cmd[i]) == ft_strlen(cmd[i]))
			{
				space = 1;
				i++;
			}
			else
				i = 1;
		}
		if (i > 1 && space == 0)
			printf(" ");
		printf("%s", cmd[i]);
		i++;
	}
	if (space == 0)
		printf("\n");
}

static int	ft_multiple_checks(char *cmd)
{
	if (ft_strncmp(cmd, "-n\0", 3) == 0)
		return (SUCCESS);
	else if (ft_strncmp(cmd, "-n", 2) == 0 && ft_isn(cmd) == ft_strlen(cmd))
		return (SUCCESS);
	else
		return (ERROR);
}

void	ft_print(char **cmd, int i)
{
	int	u;

	u = 0;
	while (cmd[i] && (ft_multiple_checks(cmd[i]) == SUCCESS) && cmd[i + 1])
		i++;
	while (cmd[i])
	{
		if (u != 0)
			printf(" ");
		u++;
		if (ft_isn(cmd[i]) != ft_strlen(cmd[i]))
			printf("%s", cmd[i]);
		i++;
	}
}

int	ft_echo(char **cmd, int i)
{
	if (cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0 && cmd[2])
		ft_print(cmd, i);
	else if (cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0)
	{
		g_exit_status = 0;
		return (SUCCESS);
	}
	else if (cmd[1])
		ft_print_multiple_param(cmd, i);
	else
		printf("\n");
	g_exit_status = 0;
	return (SUCCESS);
}
