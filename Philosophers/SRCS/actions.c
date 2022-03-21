/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:14:16 by acerdan           #+#    #+#             */
/*   Updated: 2022/03/21 14:40:29 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/philo.h"

int	ftime_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d is sleeping\n",
		ft_get_time() - philo->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	while (ft_get_time() < philo->p->time_to_sleep
		+ philo->last_meal + philo->p->time_to_eat) // why this boucle ?
	{
		usleep(philo->p->tempo);
	}
	return (1);
}

int	ftime_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d is eating\n",
		ft_get_time() - philo->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	pthread_mutex_lock(&philo->nb_meal_m);
	philo->nb_meal++; // ou est l'initialisation  ? boucle d'arret ?
	pthread_mutex_unlock(&philo->nb_meal_m);
	pthread_mutex_lock(&philo->last_meal_m);
	philo->last_meal = ft_get_time(); // why ?
	pthread_mutex_unlock(&philo->last_meal_m);
	while (ft_get_time() < philo->p->time_to_eat + philo->last_meal) // why + philo->last_meal
	{
		usleep(philo->p->tempo);
	}
	pthread_mutex_unlock(&philo->fork); // unlocked
	pthread_mutex_unlock(&philo->p->philos[(philo->index) //idem
		% philo->p->amount].fork);
	return (1);
}

int	ft_take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork); // locked
	if (ft_should_i_stop(philo) == TRUE)
		return (0);
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d has taken left fork\n",
		ft_get_time() - philo->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	return (1);
}

int	ft_take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->p->philos[(philo->index)
		% philo->p->amount].fork); // idem
	if (ft_should_i_stop(philo) == TRUE)
		return (0);
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d has taken right fork\n",
		ft_get_time() - philo->start_time, philo->index);
	pthread_mutex_unlock(&philo->p->msg_m);
	return (1);
}

int	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->p->msg_m);
	printf("%ld		%d is thinking\n",
		ft_get_time() - philo->start_time, philo->index); // difference entre le moment pù le repas a commencer et l'heure de maintenant ??
	pthread_mutex_unlock(&philo->p->msg_m);
	if (philo->nb_meal == 0 && philo->index % 2 == 0) //si le philo a pas encore manger et que sa place est paire... il dort ??
		usleep(10000); //microseconde = 1sec, prk 1sec ? prk usleep 1 sec ?
	if (!ft_take_left_fork(philo))
		return (0);
	if (!ft_take_right_fork(philo))
		return (0);
	return (1);
}
