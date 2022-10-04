/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 12:04:50 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (ft_int_len(nbr) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr *= -1;
	}
	ft_putnbr_stock(nbr, str, &i);
	str[i] = '\0';
	return (str);
}

static char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

int	ft_calc_len(char *str, char *val)
{
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (str[y])
	{
		if (str[y] != 0 && str[y] == '$' && str[y + 1] == '?')
		{
			count++;
			y += 2;
		}
		else
			y++;
	}	
	if (ft_strlen(val) == 3)
	{
		ft_strlen(str);
		return (ft_strlen(str) + 1 * count);
	}
	if (ft_strlen(val) == 1)
		return (ft_strlen(str) - 1 * count);
	else
		return (ft_strlen(str));
}

char	*doll_prog(char *str, char *val, char *new)
{
	int	y;
	int	u;
	int	k;

	u = 0;
	y = 0;
	while (str[y])
	{
		while (str[y] != 0 && str[y] == '$' && str[y + 1] == '?')
		{
			k = 0;
			while (k < ft_strlen(val))
				new[u++] = val[k++];
			new[u] = 0;
			y++;
			y++;
		}
		while (str[y] != 0 && str[y] != '$' && str[y + 1] != '?')
		{
			while (str[y] != 0 && str[y] != '$' && str[y + 1] != '?')
				new[u++] = str[y++];
			new[u] = 0;
		}
	}
	return (new);
}

int	ft_doll_int(char **str)
{
	int		i;
	char	*val;
	char	*new;

	val = NULL;
	val = ft_itoa(g_exit_status);
	if (val == NULL)
		return (ERROR_MALLOC);
	i = 0;
	while (str[i])
	{
		if (ft_strstr(str[i], "$?") != NULL)
		{
			new = NULL;
			new = malloc(sizeof(char) * (ft_calc_len(str[i], val) + 1));
			new = doll_prog(str[i], val, new);
			free(str[i]);
			str[i] = NULL;
			str[i] = ft_strdup(new);
			free(new);
		}	
		i++;
	}
	free(val);
	return (SUCCESS);
}
