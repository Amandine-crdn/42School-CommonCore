/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:17:22 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/03 14:23:54 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close(int fd, int i)
{
	if (i == 1)
	{
		close(fd);
		return (ERROR_MALLOC);
	}
	else if (i == 2)
	{
		close(fd);
		return (SUCCESS);
	}
	return (ERROR);
}

int	ft_second_open(t_game *game, int i)
{
	int		fd;
	char	*line;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		ft_exit(game, ERROR_OPEN);
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_close(fd, 1));
		if (i != game->map_height - 1)
			line[ft_strlen(line) - 1] = '\0';
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
		{
			free(line);
			return (ft_close(fd, 1));
		}
		free(line);
		i++;
	}
	return (ft_close(fd, 2));
}

int	ft_open_file(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		ft_exit(game, ERROR_OPEN);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map_height++;
		free(line);
	}
	close(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (ERROR_MALLOC);
	game->map[game->map_height] = NULL;
	ft_second_open(game, 0);
	return (SUCCESS);
}

int	ft_subword(char *s, char *pattern)
{
	int	i;
	int	j;

	i = 0;
	while (s && pattern && s[i])
	{
		j = 0;
		while (s[i] && pattern[j] && s[i + j] == pattern[j])
			j++;
		if (j == (int)ft_strlen(pattern))
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}
