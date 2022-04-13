/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:35:15 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/13 12:35:53 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_death(t_param *param, int i)
{
	int	j;

	j = 0;
	pthread_mutex_lock(&param->philos[i].last_meal_m);
	// if (ft_get_time() >= param->philos[i].last_meal + param->time_to_eat)
	
	if (ft_get_time() >= param->philos[i].last_meal)
	{
		pthread_mutex_unlock(&param->philos[i].last_meal_m);
		while (j < param->amount)
		{
			pthread_mutex_lock(&param->philos[j].last_meal_m);
			pthread_mutex_lock(&param->philos[j].stop_m);
			param->philos[j].stop = 1;
			pthread_mutex_unlock(&param->philos[j].stop_m);
			pthread_mutex_lock(&param->philos[j].fork); // et unlock quand on destroy
			pthread_mutex_unlock(&param->philos[j].last_meal_m);
			j++;
		}
		pthread_mutex_lock(&param->msg_m);
		usleep(100); // les 10sec ??
		printf("%ld %d died\n", ft_get_time() - param->start_time, param->philos[i].index);
		pthread_mutex_unlock(&param->msg_m);
		return (0);
	}
	pthread_mutex_unlock(&param->philos[i].last_meal_m);
	return (1);
}

int	ft_dinner_end(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->amount)
	{
		pthread_mutex_lock(&param->philos[i].nb_meal_m); // avec 0 ou 100 meals nerded
		if (param->philos[i].nb_meal < param->meals_needed)
		{
			pthread_mutex_unlock(&param->philos[i].nb_meal_m);
			return (0);
		}
		pthread_mutex_unlock(&param->philos[i].nb_meal_m);
		i++;
	}
	return (1);
}

int	ft_check_dinner(t_param *param)
{
	int	j;

	j = 0;
	if (ft_dinner_end(param))
	{
		while (j < param->amount)
		{
			pthread_mutex_lock(&param->philos[j].stop_m);
			param->philos[j].stop = 1;
			pthread_mutex_unlock(&param->philos[j].stop_m);
			pthread_mutex_lock(&param->philos[j].fork);
			j++;
		}
		pthread_mutex_lock(&param->msg_m);
		usleep(100);
		printf("%ld Dinner is over\n", ft_get_time()
			- param->start_time);
		pthread_mutex_unlock(&param->msg_m);
		return (0);
	}
	return (1);
}

int	ft_monitoring(t_param *param) //  2 coonditions d'arrets
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < param->amount)
		{
			if (!ft_check_death(param, i)) // dabord verifier mort puis repas
				return (0);
			if (!ft_check_dinner(param))
				return (0);
			i++;
		}
	}
}