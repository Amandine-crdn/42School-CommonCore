#include "../includes/philosophers.h"

void	clear_data(t_data *data, int n)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < n)
		{
			pthread_mutex_destroy(&(data->forks[i]));
			i++;
		}
		free (data->forks);
	}
}

static int	ft_init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_mutex) * data->args.num_philos + 1);
	if (!data->forks)
	{
		clear_data(data, data->args.num_philos);
		return (1);
	}
	i = 0;
	while (i < data->args.num_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
		{
			clear_data(data, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->args.num_philos = ft_atoi(argv[1]);
	data->args.time_to_die = ft_atoi(argv[2]);
	data->args.time_to_eat = ft_atoi(argv[3]);
	data->args.time_to_sleep = ft_atoi(argv[4]);
	if (data->args.num_philos < 1)
		return (1);
	if (argc == 6)
	{
		data->args.num_meals = ft_atoi(argv[5]);
		if (data->args.num_meals == 0)
			return (1);
	}
	else
		data->args.num_meals = -1;
	data->death = 0;
	return (0);
}

static int	parsing_data(t_data *data, int argc, char **argv)
{
	if (ft_init_data(data, argc, argv))
		return (write_error(ERROR_INVALID_ARGS, 1));
	if (ft_init_forks(data))
		return (write_error(ERROR_INIT_FORKS, 1));
	if (pthread_mutex_init(&(data->prompt_msg), NULL))
	{
		clear_data(data, data->args.num_philos);
		pthread_mutex_destroy(&(data->prompt_msg));
		return (write_error(ERROR_DATA_MUTEX, 1));
	}
	return (0);
}

int	ft_init(t_data **data, t_philo **philos, int argc, char **argv)
{
	*data = malloc(sizeof(t_data) + 1);
	if (!*data)
	{
		free(*data);
		return (write_error(ERROR_MALLOC, 1));
	}
	if (parsing_data(*data, argc, argv))
		return (1);
	*philos = malloc(sizeof(t_philo) * (*data)->args.num_philos + 1);
	if (!*philos)
	{
		free(*philos);
		return (write_error(ERROR_MALLOC, 1));
	}
	return (ft_next(*philos, *data));
}

