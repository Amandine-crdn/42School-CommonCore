/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:22:31 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/14 16:31:03 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long	current_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
	// return ((time.tv_sec * (unsigned long)1000) + time.tv_usec);
}

void	light_sleep(unsigned long duration, t_game *g)
{
	unsigned long	start_time;

	start_time = current_ms();
	while (!g->sim_over)
	{
		if (current_ms() - start_time >= duration)
			break ;
		usleep(g->amount * 2);
	}
}

void	msg(char *msg, t_philo *philo)
{
	long	time;
	int		id;

	time = current_ms() - philo->g->start_time;
	id = philo->id;
	pthread_mutex_lock(&philo->g->print_mtx);
	if (!philo->g->sim_over && !philo->g->all_full)
		printf("%ld\t%d %s\n", time, id, msg);
	pthread_mutex_unlock(&philo->g->print_mtx);
}
