/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:04:11 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/18 08:04:12 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	print_mutex(philo, TAKE_FORK);
	pthread_mutex_lock(philo->fork2);
	print_mutex(philo, TAKE_FORK);
	pthread_mutex_lock(&(philo->tamagotchi_meal));
	print_mutex(philo, EATING);
	philo->die_time = get_time() + philo->args.time_to_die;
	philo->count_meals++;
	if (!philo->data->death)
		ft_during(philo->args.time_to_eat);
	pthread_mutex_unlock(&(philo->tamagotchi_meal));
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->data->death)
	{
		philo_eating(philo);
		print_mutex(philo, SLEEPING);
		if (!philo->data->death)
			ft_during(philo->args.time_to_sleep);
		print_mutex(philo, THINKING);
	}
	return (NULL);
}

void	*unique_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(philo->fork1);
	print_mutex(philo, TAKE_FORK);
	ft_during(philo->args.time_to_die);
	print_mutex(philo, DIE);
	pthread_mutex_unlock(philo->fork1);
	return (NULL);
}
