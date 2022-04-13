/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:14:16 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/13 12:10:56 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ftime_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d is sleeping\n", ft_get_time() - philo->p->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	// while (ft_get_time() < philo->p->time_to_sleep + philo->p->philos->last_meal + philo->p->time_to_eat) // why this boucle ?
	// {
	// 	usleep(philo->p->tempo);
	// }
	usleep(philo->p->time_to_sleep * 1000);
	return (1);
}

int	ftime_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d is eating\n", ft_get_time() - philo->p->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);


	pthread_mutex_lock(&philo->last_meal_m); // noter son dernier repas quand il commence
	philo->p->philos->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->last_meal_m);
	
	usleep(philo->p->time_to_eat * 1000);

	pthread_mutex_lock(&philo->p->philos->nb_meal_m); //apres avoir manger
	philo->p->philos->nb_meal++;
	pthread_mutex_unlock(&philo->p->philos->nb_meal_m);

	int p = 0;
	int a = 0;
	pthread_mutex_unlock(&philo->p->philos[philo->index].fork);
	if (philo->index == philo->p->amount) // si c'est le dernier rends la fourchette du 1
	{
		while (philo->index != 1)
		{
			philo->index--;
			p++;
		}
		pthread_mutex_unlock(&philo->p->philos[philo->index].fork);
		while (a < p)
		{
			philo->index++;
			a++;
		}
	}
	else
		pthread_mutex_unlock(&philo->p->philos[philo->index + 1].fork); // si  philo->index - 1 ne prends pas sa fourchette droite
	return (1);
}

int	ft_right_fork(t_philo *philo)
{
	int p = 0;
	int a = 0;
	// if (ft_should_i_stop(philo) == TRUE)
	// 	return (0);
		
	if (philo->index == philo->p->amount) // si c'est le dernier prends la fourchette du 1
	{
		while (philo->index != 1)
		{
			philo->index--;
			p++;
		}
		pthread_mutex_lock(&philo->p->philos[philo->index].fork);
		while (a < p)
		{
			philo->index++;
			a++;
		}
	}
		
	else
		pthread_mutex_lock(&philo->p->philos[philo->index + 1].fork); //fourchette de gauche de son voisin
		
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d has taken right fork\n", ft_get_time() - philo->p->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	return (1);
}

int	ft_left_fork(t_philo *philo)
{
	// if (ft_should_i_stop(philo) == TRUE) // prk ne pas mettre avant ? ne marche pas
	// 	return (0);

	pthread_mutex_lock(&philo->p->philos[philo->index].fork); // 1 ou plusieurs c'est sa fourchette
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d has taken left fork\n", ft_get_time() - philo->p->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	return (1);
}

int	ft_think(t_philo *philo)
{
	// avant de penser compte a rebours enclencher
	pthread_mutex_lock(&philo->last_meal_m);
	philo->p->philos->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->last_meal_m);
	if (/*philo->p->philos->nb_meal == 0 && */philo->index % 2 == 0)
		usleep(philo->p->tempo);
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d is thinking\n", ft_get_time() - philo->p->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	if (!ft_left_fork(philo))
		return (0);
	if (!ft_right_fork(philo))
		return (0);
	return (1);
}