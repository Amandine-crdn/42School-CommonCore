/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:28:35 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/12 10:51:17 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_should_i_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop_m);
	if (philo->stop == 1)
	{
		pthread_mutex_unlock(&philo->stop_m);
		return (1);
	}
	pthread_mutex_unlock(&philo->stop_m);
	return (0);
}

void	ft_mutex_destroy(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->amount)
	{
		pthread_mutex_unlock(&p->philos[i].fork);
		pthread_mutex_destroy(&p->philos[i].fork);
		i++;
	}
}

long	ft_get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	*ft_philo(void *data) // car void tout seul pas possible ?
{
	t_philo	*philo;

	philo = (t_philo *)data;
	//philo->start_time = ft_get_time(); //le set plus tard
	pthread_mutex_lock(&philo->last_meal_m); //on bloque le temps pour le donner au last meal ?
	 // a chaque depart de chaue philo son temps de repas est enclenche
	pthread_mutex_unlock(&philo->last_meal_m);
	while (1)
	{
		if (!ft_think(philo))
			break ;
		if (ft_should_i_stop(philo) == TRUE)
			return (0);
		if (!ftime_to_eat(philo))
			break ;
		if (ft_should_i_stop(philo) == TRUE)
			return (0);
		if (!ftime_to_sleep(philo))
			break ;
		if (ft_should_i_stop(philo) == TRUE)
			return (0);
	}
	return (0);
}