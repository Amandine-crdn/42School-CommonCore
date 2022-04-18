#include "../includes/philosophers.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	number;

	i = 0;
	number = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i++] - 48;
	}
	return (number);
}

static int	ft_check_valid_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] == ' ')
		i++;
	if (argv[i] == '+')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	while (argv[i] == ' ')
		i++;
	if (argv[i] != 0)
		return (0);
	return (1);
}

int	ft_check_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_check_valid_arg(argv[i]) == 0 || ft_atoi(argv[i]) > INT_MAX
		 || ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}
