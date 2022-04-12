/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:18:13 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/12 08:23:04 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	number;

	i = 0;
	number = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i++] - 48;
	}
	return (number);
}

int	ft_check_valid_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] == ' ')
		i++;
	if (argv[i] == '+')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	while (argv[i] == ' ')
		i++;
	if (argv[i] != 0)
		return (FALSE);
	return (TRUE);
}

//value_return necessaire ?
int	ft_print_error(char *str, int value_return)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write (2, str, len);
	return (value_return);
}

int	ft_check_errors(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_valid_arg(argv[i]) == FALSE)
			return (ft_print_error("Error : Wrong argument format\n", 0));
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < 0) // inférieur ou <= 0 ??
			return (ft_print_error("Error : Wrong int limit\n", 0));
		if ((i == 4 || i == 0) && ft_atoi(argv[i]) == FALSE)
			return (0);
		i++;
	}
	return (1);
}