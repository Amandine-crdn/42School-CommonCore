#include "../includes/philosophers.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_during(long long time_ms)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time();
	current_time = start_time;
	while (current_time - start_time < time_ms)
	{
		usleep(50);
		current_time = get_time();
	}
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_mutex(t_philo *philo, char *mess)
{
	pthread_mutex_lock(&(philo->data->prompt_msg));
	if (!philo->data->death)
		printf("\033[0;37m%5lld\033[0m \033[1;36m%d\033[0m %s\n", \
		get_time() - philo->data->start_program, philo->id_philo + 1, mess);
	pthread_mutex_unlock(&(philo->data->prompt_msg));
}

void	happy_end_print(t_philo *philo, char *mess)
{
	pthread_mutex_lock(&(philo->data->prompt_msg));
	if (!philo->data->death)
		printf("\n\033[1;33m%s\033[0m\n", mess);
	pthread_mutex_unlock(&(philo->data->prompt_msg));
}
