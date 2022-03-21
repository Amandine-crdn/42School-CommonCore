/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:50:29 by acerdan           #+#    #+#             */
/*   Updated: 2022/03/21 14:40:53 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	pthread_t		thread; // où?
	pthread_mutex_t	fork;				//2
	long			last_meal;
	pthread_mutex_t	last_meal_m;		//3
	int				nb_meal;
	pthread_mutex_t	nb_meal_m;			//4
	int				stop;
	pthread_mutex_t	stop_m;				//5
	int				index;
	long			start_time;
	struct s_param	*p;
}	t_philo;

typedef struct s_param
{
	int				amount;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_needed;
	t_philo			*philos;
	pthread_mutex_t	msg_m;				//1er mutex
	int				tempo;
}	t_param;

int			ft_print_error(char *str, int value_return);
long int	ft_atoi(const char *str);
int			ft_check_errors(char **argv);
int			ft_dinner_end(t_param *param);
void		*ft_philo(void *param);
long		ft_get_time(void);
void		ft_mutex_destroy(t_param *param);
int			ft_take_first_fork(t_philo *philo);
int			ft_take_second_fork(t_philo *philo);
int			ft_think(t_philo *philo);
int			ftime_to_eat(t_philo *philo);
int			ftime_to_sleep(t_philo *philo);
int			ft_should_i_stop(t_philo *philo);
int			ft_check_death(t_param *param, int i);
int			ft_dinner_end(t_param *param);
int			ft_check_dinner(t_param *param, int i);
int			ft_monitoring(t_param *param);

#endif