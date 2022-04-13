/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:22:31 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/13 11:31:17 by acerdan          ###   ########.fr       */
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
	//variable
	struct s_param	*p;
	int				index;
	long			last_meal;
	int				nb_meal;
	int				stop;
	//mutex
	pthread_mutex_t	fork;				
	pthread_mutex_t	last_meal_m;		
	pthread_mutex_t	nb_meal_m;			
	pthread_mutex_t	stop_m;				
	//reste
	
	pthread_t		thread;

}	t_philo;

typedef struct s_param
{
	int				amount;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_needed;
	t_philo			*philos;
	long			start_time;
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
int			ft_first_fork(t_philo *philo);
int			ft_second_fork(t_philo *philo);
int			ft_think(t_philo *philo);
int			ftime_to_eat(t_philo *philo);
int			ftime_to_sleep(t_philo *philo);
int			ft_should_i_stop(t_philo *philo);
int			ft_check_death(t_param *param, int i);
int			ft_dinner_end(t_param *param);
int			ft_check_dinner(t_param *param);
int			ft_monitoring(t_param *param);

#endif