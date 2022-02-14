/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:22:31 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/08 23:39:54 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define WRONG_N_ARGS 1
# define INVALID_ARG 2
# define PTHD_ERR 3
# define MALLOC_ERR 4
# define MUTEX_ERR 5

struct	s_game;

typedef struct s_philo
{
	int				meals;
	int				id;
	int				fork1;
	int				fork2;
	unsigned long	meal_ms;
	struct s_game	*g;
	pthread_t		thd;
}				t_philo;

typedef struct s_game
{
	int				amount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_needed;
	unsigned long	start_time;
	int				sim_over;
	int				all_full;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_chk_mtx;
	pthread_mutex_t	print_mtx;
}				t_game;

int				print_error(int err);
int				ft_atoi(const char *nptr);
int				init_data(t_game *g);
void			msg(char *msg, t_philo *f);
void			eat(t_philo *philo);
void			monitor(t_game *g);
int				init_threads(t_game *g);
unsigned long	current_ms(void);
void			light_sleep(unsigned long duration, t_game *g);
void			*philo_thd(void *args);

#endif
