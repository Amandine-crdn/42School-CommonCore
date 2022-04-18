#include "../includes/philosophers.h"

void	ccleaner(t_data *data, t_philo *philos, int res)
{
	int i;

	if (philos)
	{
		i = 0;
		while (i < res)
		{
			pthread_mutex_destroy(&(philos[i].tamagotchi_meal));
			i++;
		}
		free(philos);
	}
	if (data)
		clear_data(data, data->args.num_philos);
}

static int	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.num_philos)
	{
		philos[i].args.num_philos = data->args.num_philos;
		philos[i].args.time_to_die = data->args.time_to_die;
		philos[i].args.time_to_eat = data->args.time_to_eat;
		philos[i].args.time_to_sleep = data->args.time_to_sleep;
		philos[i].args.num_meals = data->args.num_meals;
		philos[i].id_philo = i;
		philos[i].count_meals = 0;
		philos[i].data = data;
		philos[i].fork1 = data->forks + (i + i % 2) % data->args.num_philos;
		if (data->args.num_philos != 1)
			philos[i].fork2 = data->forks + \
			(i + 1 - i % 2) % data->args.num_philos;
		else
			philos[i].fork2 = NULL;
		if (pthread_mutex_init(&(philos[i].tamagotchi_meal), NULL))
			return (i);
		i++;
	}
	return (0);
}

int	ft_next(t_philo *philos, t_data *data)
{
	int res;
	res = init_philos(philos, data);
	if (res)
	{
		ccleaner(data, philos, res);
		pthread_mutex_destroy(&(data->prompt_msg));
		return (write_error(ERROR_INIT_PHILOS, 1));
	}
	return (0);
}
