#include "microshell.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str && str[i])
        i++;
    return (i);
}

int	ft_putstr_fd2(char *str, char *arg)
{
	if (str)
		write(2, str, ft_strlen(str));
	if (arg)
		write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	return (1);
}

int ft_execute(char **env, char **argv, int i, int tmp_fd) //child
{
	argv[i] = NULL;
	dup2(tmp_fd, 0);
	close(tmp_fd);
	execve(argv[0], argv, env);
	return (ft_putstr_fd2("error: cannot execute ", argv[0]));
}

int	main(int argc, char *argv[], char *env[])
{
    // 5 variables
	int	i = 0;
	int pid = 0;
	int fd[2];
	int tmp_fd = dup(0);
	(void)argc;	// is needed in exam, because the exam tester compiles with -Wall -Wextra -Werror

	while (argv[i] && argv[i + 1]) //check if the end is reached
	{
        argv = &(argv[i + 1]);
		i = 0;
		//count until we have all informations to execute the next child;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
		{
			i++;
		}
		if (strcmp(argv[0], "cd") == 0 && i == 2 && chdir(argv[1]) != 0) //cd
			ft_putstr_fd2("error: cd: cannot change directory to ", argv[1]);
		else if (strcmp(argv[0], "cd") == 0 && i != 2)
			ft_putstr_fd2("error: cd: bad arguments", NULL);
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				if (ft_execute(env, argv, i, tmp_fd))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, 2) != -1)
					;
				tmp_fd = dup(0);
			}
		}
		else if(i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(env, argv, i, tmp_fd))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}