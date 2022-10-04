/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 07:59:37 by acerdan           #+#    #+#             */
/*   Updated: 2022/04/19 07:41:43 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define ERROR_NUM_ARGS "Error: invalid number of arguments"
# define ERROR_INVALID_ARGS "Error: invalid input arguments"
# define ERROR_MALLOC "Error: malloc"
# define ERROR_INIT_FORKS "Error: init forks"
# define ERROR_DATA_MUTEX "Error: init data mutex"
# define ERROR_INIT_PHILOS "Error: init philos"
# define HAPPY_END "Dinner is over :) ! YUUMMI"
# define TAKE_FORK "\033[1;34mhas taking a fork\033[0m"
# define EATING "\033[1;32mis eating\033[0m"
# define SLEEPING "\033[1;35mis sleeping\033[0m"
# define THINKING "\033[1;36mis thinking\033[0m"
# define DIE "\033[1;31mdied\033[0m"

typedef pthread_mutex_t	t_mutex;

typedef struct s_args
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_meal;
}				t_args;

typedef struct s_data
{
	t_mutex			*forks;
	t_mutex			prompt_msg;
	t_args			args;
	int				death;
	long long int	start_program;
}				t_data;

typedef struct s_philo
{
	t_args			args;
	t_data			*data;
	int				id_philo;
	int				count_meals;
	long long int	die_time;
	t_mutex			*fork1;
	t_mutex			*fork2;
	t_mutex			tamagotchi_meal;
	pthread_t		pid_pthread;
}				t_philo;

int			ft_check_errors(int argc, char **argv);
int			ft_init(t_data **data, t_philo **philos, int argc, char **argv);
int			parsing_philos(t_philo *philos, t_data *data);

void		*unique_routine(void *args);
void		*routine(void *args);
void		ccleaner(t_data *data, t_philo *philos, int res);
void		clear_data(t_data *data, int n);
int			ft_next(t_philo *philos, t_data *data);

int			write_error(char *mess, int code);
size_t		ft_strlen(char const *str);
long int	ft_atoi(const char *str);
long long	get_time(void);
void		ft_during(long long time_ms);
void		print_mutex(t_philo *philo, char *mess);
void		happy_end_print(t_philo *philo, char *mess);

#endif