/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:22:24 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/14 15:14:02 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error(int err)
{
	char	*str;

	if (err == WRONG_N_ARGS)
		str = "Wrong number of arguments\n";
	if (err == INVALID_ARG)
		str = "Invalid argument (only > 0 int)\n";
	if (err == PTHD_ERR)
		str = "Error creating thread\n";
	if (err == MALLOC_ERR)
		str = "Error allocating memory\n";
	if (err == MUTEX_ERR)
		str = "Error initializing mutex\n";
	printf("%s", str);
	if (err == WRONG_N_ARGS)
	{
		printf("Arguments: number_of_philosophers ");
		printf("time_to_die time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
	}
	return (1);
}
