/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:43:05 by acerdan           #+#    #+#             */
/*   Updated: 2021/10/07 08:43:07 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *str, char **env, int i)
{
	char	**global_path;
	char	*tmp;
	char	*curr_path;

	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			global_path = ft_split(&env[0][5], ':');
		env++;
	}
	while (global_path && global_path[i])
	{
		tmp = ft_strjoin(global_path[i], "/");
		curr_path = ft_strjoin(tmp, str);
		if (access(curr_path, X_OK) != -1)
		{
			free_strs(global_path, NULL);
			return (curr_path);
		}
		i++;
		free(curr_path);
		free(tmp);
	}
	free_strs(global_path, NULL);
	return (NULL);
}

void	run_cmd1(t_data *d, char **av, char **env)
{
	int	j;

	if (check_no_space(av[2]))
		d->cmd1 = ft_split(av[2], ' ');
	else
		d->cmd1 = ft_split(av[2], '\0');
	d->path1 = find_path(d->cmd1[0], env, 0);
	if (d->path1 == NULL)
		ft_quit(d->cmd1[0], 0);
	dup2(d->pipefd[1], STDOUT_FILENO);
	dup2(d->file1, STDIN_FILENO);
	close_fd(d);
	j = open(av[1], O_RDONLY);
	if (j != -1)
		execve(d->path1, d->cmd1, env);
	d->pid1 = 0;
	close(j);
}

void	run_cmd2(t_data *d, char *argv[], char **env)
{
	if (check_no_space(argv[3]))
		d->cmd2 = ft_split(argv[3], ' ');
	else
		d->cmd2 = ft_split(argv[3], '\0');
	d->path2 = find_path(d->cmd2[0], env, 0);
	if (d->path2 == NULL)
		ft_quit(d->cmd2[0], 0);
	dup2(d->pipefd[0], STDIN_FILENO);
	dup2(d->file2, STDOUT_FILENO);
	close_fd(d);
	execve(d->path2, d->cmd2, env);
}

void	ft_quit(char *str, int i)
{
	if (errno)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	if (i == 0)
		exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **env)
{	
	t_data	data;

	if (argc != 5)
		ft_quit("Incorrect number of arguments in command line\n", 0);
	data.file1 = open(argv[1], O_RDONLY);
	if (data.file1 == -1)
		ft_quit(argv[1], 1);
	data.file2 = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (data.file2 == -1)
		ft_quit(argv[4], 0);
	if (pipe(data.pipefd) == -1)
		ft_quit("Error with pipe function\n", 0);
	if (data.file1 != -1)
		data.pid1 = fork();
	if (data.pid1 == 0)
		run_cmd1(&data, argv, env);
	data.pid2 = fork();
	if (data.pid2 == 0)
		run_cmd2(&data, argv, env);
	close_fd(&data);
	if (data.file1 != -1)
		waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	return (0);
}
