/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:22:18 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/14 16:45:12 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	deinit(t_game *g)
{
	int	i;

	i = 0;
	while (++i < g->amount)
	{
		pthread_join(g->philos[i].thd, NULL);
		i++;
	}
	i = 0;
	while (i < g->amount)
	{
		pthread_mutex_destroy(&g->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&g->meal_chk_mtx);
	pthread_mutex_destroy(&g->print_mtx);
	free(g->philos);
	free(g->forks);
}

int	init_threads(t_game *g)
{
	int	i;

	i = 0;
	g->start_time = current_ms();
	while (i < g->amount)
	{
		g->philos[i].meal_ms = current_ms();
		if (pthread_create(&g->philos[i].thd,
				NULL, philo_thd, &(g->philos[i])))
			return (print_error(PTHD_ERR));
		i++;
	}
	return (0);
}

int	init_data(t_game *g)
{
	int	i;

	g->philos = malloc(sizeof(t_philo) * g->amount);
	g->forks = malloc(sizeof(pthread_mutex_t) * g->amount);
	if (!g->philos || !g->forks)
		return (print_error(MALLOC_ERR));
	i = 0;
	while (i < g->amount)
	{
		if (pthread_mutex_init(&(g->forks[i]), NULL))
			return (PTHD_ERR);
		g->philos[i].meals = 0;
		g->philos[i].id = i + 1;
		g->philos[i].fork1 = i;
		g->philos[i].fork2 = (i + 1) % g->amount;
		g->philos[i].g = g;
		i++;
	}
	if (pthread_mutex_init(&g->meal_chk_mtx, NULL))
		return (print_error(PTHD_ERR));
	if (pthread_mutex_init(&g->print_mtx, NULL))
		return (print_error(PTHD_ERR));
	return (0);
}

int	read_args(int argc, char *argv[], t_game *g)
{
	if (argc != 5 && argc != 6)
		return (print_error(WRONG_N_ARGS));
	g->amount = (long int)ft_atoi(argv[1]);
	g->time_to_die = (long int)ft_atoi(argv[2]);
	g->time_to_eat = (long int)ft_atoi(argv[3]);
	g->time_to_sleep = (long int)ft_atoi(argv[4]);
	g->meals_needed = 0;
	if (argc == 6)
	{
		g->meals_needed = ft_atoi(argv[5]);
		if (g->meals_needed < 0)
			return (print_error(INVALID_ARG));
	}
	if (g->amount <= 0 || g->time_to_die <= 0
		|| g->time_to_eat <= 0 || g->time_to_sleep <= 0)
		return (print_error(INVALID_ARG));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	game.all_full = 0;
	game.sim_over = 0;
	if (read_args(argc, argv, &game))
		return (1);
	if (init_data(&game))
		return (1);
	if (init_threads(&game))
		return (1);
	monitor(&game);
	pthread_mutex_unlock(&game.print_mtx);
	deinit(&game);
	return (0);
}
