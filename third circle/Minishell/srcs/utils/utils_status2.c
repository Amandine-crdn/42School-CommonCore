/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_status2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:45:21 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 11:48:52 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	attribute_exit_status(int status)
{
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit_status = WTERMSIG(status) + 128;
	else if (WIFSTOPPED(status))
		g_exit_status = WSTOPSIG(status) + 128;
}

int	ft_int_len(long long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_stock(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnbr_stock(n / 10, str, i);
		ft_putnbr_stock(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}
