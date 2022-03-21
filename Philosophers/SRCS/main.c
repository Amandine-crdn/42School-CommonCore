/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:49:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/03/21 14:40:39 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/philo.h"

int	ft_get_param(t_param *param, char **argv)
{
	param->amount = ft_atoi(argv[1]);
	if (param->amount < 60)
		param->tempo = 100; // what is tempo ?
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
	if (pthread_mutex_init(&param->msg_m, NULL)) //why msg_m, why init thread mutex ? prompteur mssage ?
		return (0);
	return (1);
}

int	ft_launch_thread(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->amount)
	{
		printf("--- i = %d ----\n", i);
		// où est l'initialisation de thread ?? aah pas mutex donc pas init jsut create ??
		if (pthread_create(&param->philos[i].thread, NULL,
				ft_philo, &param->philos[i]) != 0)
			return (0);
		i++;
	}
	usleep(100); //?? il ne doit pas y avoir plus de 10 ms entre la mort d’un philosophe et l’affichage du message annonçant sa mort.
	ft_monitoring(param);
	i = 0;
	while (i < param->amount)
	{
		if (pthread_join(param->philos[i].thread, NULL) != 0) // prk cette boucle ? et prk apres ?
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_table(t_param *param)
{
	int		i;
	t_philo	philo;

	i = 0;
	param->philos = malloc(sizeof(t_philo) * param->amount);
	if (!param->philos)
		return (0);
	while (i < param->amount)
	{
		philo.index = i + 1;
		philo.p = param;
		philo.last_meal = 0;
		philo.nb_meal = 0;
		philo.stop = 0;
		param->philos[i] = philo; // 4 mutex  ? juste init ?
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
	if (!ft_get_param(&param, argv) || !ft_init_table(&param))
		return (0);
	if (!ft_launch_thread(&param))
		return (0);
	ft_mutex_destroy(&param);
	free(param.philos); // et free param ??
	return (0);
}
