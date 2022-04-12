/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:49:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/12 12:02:48 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_init_s_param(t_param *param, char **argv)
{
	param->amount = ft_atoi(argv[1]);
	if (param->amount < 60)
		param->tempo = 100;                       // what is tempo ?
	else if (param->amount < 120)
		param->tempo = 500;
	else
		param->tempo = 1000;
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		param->meals_needed = ft_atoi(argv[5]);
	else
		param->meals_needed = 0;
	if (pthread_mutex_init(&param->msg_m, NULL)) 
		return (0);
	return (1);
}

int	ft_launch_thread(t_param *param)
{
	int	i;

	i = 0;
	 //le set plus tard
	param->start_time = ft_get_time();
	while (i < param->amount)
	{
		
		//param->philos[i].last_meal = param->philos->start_time ;
		if (pthread_create(&param->philos[i].thread, NULL,
				ft_philo, &param->philos[i]) != 0)
			return (0);
		i++;
		usleep(100);
	}
	
	//?? laisser le temps au programme de se lire et avancer ??
	ft_monitoring(param);
	i = 0;
	while (i < param->amount)
	{
		if (pthread_join(param->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_s_philo(t_param *param)
{
	int		i;
	t_philo	philo;

	i = 0;
	param->philos = malloc(sizeof(t_philo) * param->amount);
	if (!param->philos)
		return (0);
	while (i < param->amount)
	{
		philo.p = param;
		philo.index = i + 1;
		philo.last_meal = 0;
		philo.nb_meal = 0;
		philo.stop = 0;
		param->philos[i] = philo;
		if (pthread_mutex_init(&param->philos[i].fork, NULL)
			|| pthread_mutex_init(&param->philos[i].stop_m, NULL)
			|| pthread_mutex_init(&param->philos[i].last_meal_m, NULL)
			|| pthread_mutex_init(&param->philos[i].nb_meal_m, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc < 5 || argc > 6)
		return (ft_print_error("Error : Wrong number of arguments\n", 0));
	if (ft_check_errors(argv) == FALSE)
		return (0);
	if (!ft_init_s_param(&param, argv) || !ft_init_s_philo(&param))
		return (0);
	if (!ft_launch_thread(&param))
		return (0);
	ft_mutex_destroy(&param);
	free(param.philos); // et free param ??
	return (0);
}