/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/07/26 07:51:15 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_in_stdin(int fd, char *word)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			exit(0);
		if (!ft_strncmp(word, line, ft_strlen(word) + 1))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
}

int	ft_heredoc(char *word)
{
	int	fd;

	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	ft_read_in_stdin(fd, word);
	fd = open(".heredoc_tmp", O_RDONLY);
	if (fd < 0)
		unlink(".heredoc_tmp");
	return (fd);
}

int	ft_open_files(char *filename, int type)
{
	int	fd;

	if (type == HEREDOC)
	{
		fd = ft_heredoc(filename);
		if (fd >= 0)
			unlink(".heredoc_tmp");
	}
	else if (type == INPUT)
		fd = open(filename, O_RDONLY, 0644);
	else if (type == TRUNC)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		return (-2);
	if (fd < 0)
		return (ERROR);
	return (fd);
}
