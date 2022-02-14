/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:22:31 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/14 16:33:13 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat(t_philo *f)
{
	pthread_mutex_lock(&f->g->forks[f->fork1]);
	msg("has taken a fork", f);
	pthread_mutex_lock(&f->g->forks[f->fork2]);
	msg("has taken a fork", f);
	pthread_mutex_lock(&f->g->meal_chk_mtx);
	msg("is eating", f);
	f->meal_ms = current_ms();
	pthread_mutex_unlock(&f->g->meal_chk_mtx);
	light_sleep(f->g->time_to_eat, f->g);
	f->meals++;
	pthread_mutex_unlock(&f->g->forks[f->fork2]);
	pthread_mutex_unlock(&f->g->forks[f->fork1]);
}

void	*philo_thd(void *args)
{
	int		i;
	t_philo	*f;
	t_game	*g;

	i = 0;
	f = (t_philo *)args;
	g = f->g;
	if (f->id % 2 && g->amount > 1)
		light_sleep(g->time_to_eat / 50, g);
	while (!g->sim_over && !g->all_full)
	{
		eat(f);
		msg("is sleeping", f);
		light_sleep(g->time_to_sleep, g);
		msg("is thinking", f);
	}
	return (NULL);
}

void	hunger_chk(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->amount && !g->sim_over)
	{
		pthread_mutex_lock(&g->meal_chk_mtx);
		if (current_ms() - g->philos[i].meal_ms >= g->time_to_die)
		{
			msg("died", &g->philos[i]);
			pthread_mutex_lock(&g->print_mtx);
			g->sim_over = 1;
		}
		pthread_mutex_unlock(&g->meal_chk_mtx);
		i++;
	}
}

void	monitor(t_game *g)
{
	int	i;
	int	philos_full;

	while (!g->all_full)
	{
		hunger_chk(g);
		if (g->sim_over)
			break ;
		i = 0;
		philos_full = 0;
		while (g->meals_needed && i < g->amount)
		{
			if (g->philos[i].meals >= g->meals_needed)
				philos_full++;
			i++;
		}
		if (philos_full >= g->amount)
			g->all_full = 1;
		usleep(g->amount);
	}
}
