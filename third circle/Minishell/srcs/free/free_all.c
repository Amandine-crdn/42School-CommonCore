/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/27 11:25:34 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < size)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
}

void	ft_free_cmd_tab(t_cmd *cmd_tab)
{
	int	i;
	int	j;

	i = 0;
	if (cmd_tab)
	{
		while (cmd_tab[i].cmd_param)
		{
			j = 0;
			while (cmd_tab[i].cmd_param[j])
			{
				free(cmd_tab[i].cmd_param[j]);
				j++;
			}
			free(cmd_tab[i].cmd_param);
			i++;
		}
		free(cmd_tab);
	}
}

void	ft_free_double_tab(t_cmd *cmd_tab, char **tab, int size, int status)
{
	ft_free_cmd_tab(cmd_tab);
	ft_free_tab(tab, size);
	if (status == 1)
		g_exit_status = 127;
}

void	ft_free_two_str(char *s, char *s2)
{
	free(s);
	free(s2);
}

int	ft_print_error_token(int err, char *token)
{
	if (err == ERROR_SYNTAX)
		printf("%s : syntax error\n", token);
	else if (err == ERROR_COMMAND)
		printf("%s: command not found\n", token);
	else if (err == PB_OPEN)
		printf("Error open\n");
	else if (err == ERROR_FILE_DIRECTORY)
		printf("%s: no such file or directory\n", token);
	else if (err == ERROR_MALLOC)
		printf("Malloc error\n");
	else if (err == ERROR_MALLOC_MAIN)
	{
		printf("Malloc error\n");
		g_exit_status = 127;
	}
	else if (err == ERROR_PIPE)
		printf("Pipe error\n");
	else if (err == ERROR_FORK)
		printf("Fork error\n");
	else if (err == ERROR)
		printf("Error\n");
	else if (err == END_MINISHELL)
		printf("Error : error nb arguments\n");
	return (err);
}
