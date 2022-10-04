/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/08/02 16:54:37 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/time.h>
# include <string.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>

# define EXIT					2
# define SUCCESS				1
# define ERROR					0
# define ERROR_EXIT				-1
# define ERROR_MALLOC			-2
# define ERROR_USAGE			-3
# define PB_OPEN				-4
# define ERROR_FORK				-5
# define ERROR_PIPE				-6
# define ERROR_SYNTAX			-7
# define ERROR_COMMAND			-8
# define ERROR_PATH				-9
# define ERROR_FILE_DIRECTORY	-10
# define ERROR_MALLOC_MAIN		-11
# define NO_BUILTIN				4
# define ABS_SYMBOL				5
# define SYMBOL					6

# define HEREDOC				20
# define APPEND					21
# define TRUNC					22
# define INPUT					23

# define STATUS					41
# define END_MINISHELL			42

extern int	g_exit_status;

typedef struct s_cmd
{
	char	**cmd_param;
	int		infile;
	int		outfile;
	int		pid;
	int		i;
	int		j;
	int		res;
	int		cmd_nb;
}				t_cmd;

typedef struct s_win
{
	int		len_tab;
	int		err_malloc;
	char	*input;
	char	**tab_line;
	int		len_env;
	int		pid;
	char	**env;
	char	*save;
	int		nb_pipe;
	int		i;
	int		y;
	int		size;
	char	*res;
	char	*tmp;
	char	*tmp_old;
	char	*tmp_home;
	char	*copy;
	char	**tab;
	int		j;
	int		len;
	int		a;
	int		memory;
	char	*current_path;
	int		*value_cmd_path;
}				t_win;

typedef struct s_split
{
	int		i;
	int		j;
	int		temp;
	int		i_len;
	int		len_sentence;
	char	*s;
	int		spe;
	char	**new;
	char	*path;
	char	*new_str;
	char	fixe;
	int		symb;
}				t_split;

//init
int		ft_init_win(char **env, t_win *win);
int		check_viability(t_split *split);
int		ft_count_guillemet(t_win *win);
char	**ft_copy_env(char **new_env, char **old_env, int size);
void	ft_init_val(t_win *win);
void	ft_init_val_cmd(t_cmd *cmd);

//split
char	**ft_split_init(t_win *win, t_split *split);
char	**ft_split_path(char *s, char c);
char	*check_path_exist(char **env, char *tab, t_win *win);
int		check_symbol(t_split *split, t_win *win);
char	*ispathok_split(char **env, char *tab, t_win *win);
char	*ft_err_malloc(t_win *win, char *word);
int		check_symbol2(t_split *split, t_win *win);
void	ft_increment(t_split *split, int a);
int		check_return(t_split *split, char d);
int		ft_count_sentence(t_split *split, t_win *win);
int		*ft_hav_tab_len(t_split *split, t_win *win);
int		check_fixe(t_split *split);
int		initialize_fixe(t_split *split);
int		choice_road(t_split *split);

// Print error messages
int		ft_print_error_token(int err, char *token);

// String utils
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
char	*ft_strdup(char *s1);

// FREE
int		ft_free_str_int(char *s, int err);
int		ft_free_tab_int(char **big, int err);
void	ft_free_tab(char **tab, int size);
void	ft_free_two_str(char *s, char *s2);
char	*free_errormalloc_return_null(char *s);
char	**ft_free_str_null_tab(int *s, char *s2, char **s3);
void	ft_free_cmd_tab(t_cmd *cmd_tab);
int		ft_free_null_int(char *s, char *s2, int err);
void	ft_free_double_tab(t_cmd *cmd_tab, char **tab, int size, int status);

// PARSING CMD
int		ft_parse_cmd(t_win *win, char **cmd);
int		ft_count_pipeee(t_win *win);

// BUILTIN
int		ft_echo(char **cmd, int i);
int		ft_pwd(t_win *win, char **cmd);
int		ft_unset(t_win *win, char **cmd);
int		ft_export_env(t_win *win, char **cmd);
int		ft_print_env(t_win *win, char **cmd);
int		ft_exit(char **cmd);
char	**ft_split_export(t_win *win);

// UTILS BUITIN
char	*ft_strnstr_check(char *big, char *little, size_t len);
int		ft_strchr_export(char *s, int c);
int		ft_len_env(char **env);
int		transform_len(char *s);

// UTILS CD
int		ft_previous(t_win *win, int compteur);
int		ft_home(t_win *win);
int		ft_racine(t_win *win);
int		ft_return(t_win *win);
char	*ft_give_path(t_win *win, char *str, int i);
char	*ft_replace(t_win *win, char *current_path, char *var_path, int p);
int		ft_count_slash(t_win *win);
int		ft_cd_recup(t_win *win, char **recup);
int		ft_cd_pp(t_win *win, char *cmd);
char	*ft_check_pwd(t_win *win);
char	*ft_check_home(t_win *win);
int		count_tild(char *cmd);
char	*ft_modif_env(t_win *win, char *current_path, char *var_path, int i);
char	*ft_clean_cmd(char *cmd);
int		choice_suite(t_win *win);
int		ft_creation(t_win *win);

//utils check cd
int		ft_check_cd(t_win *win, char **cmd);
int		creation_malloc(char *cmd, t_win *win);
int		creation_tab(t_win *win);
int		count_word(char *cmd);
int		ft_move(t_win *win, char *cmd, char *tmp, char *res);

//cd initialisation
int		choice_current_path(char **cmd, t_win *win);
int		ft_return_value(t_win *win, char **cmd);

// Execution
char	*find_path_char(char *tab_line, t_win *win, int i);
int		ft_check_own_builtin(char *cmd);
int		ft_open_files(char *filename, int type);
int		ft_save_cmd(t_win *win, t_cmd *tab);
int		ft_launch_cmd(t_cmd *cmd_tab, t_win *win, int launch);
int		ft_count_wordee(char **tab_word);
int		ft_check_type(char *s);
void	ft_read_in_stdin(int fd, char *word);
int		ft_heredoc(char *word);
void	set_child_process(t_cmd *cmd_tab, int nbr_cmd, int nb_pipe, int *fd);
void	set_parent_process(t_cmd *cmd_tab, int nbr_cmd, int nb_pipe, int *fd);
int		ft_wait(int count_pipe, t_cmd *cmd_tab);
void	ft_write_error_cmd(int res);
int		ft_count_pipeee(t_win *win);

// Status
void	attribute_exit_status(int status);
int		ft_int_len(long long n);
void	ft_putnbr_stock(long n, char *str, int *i);
int		ft_doll_int(char **str);

// Signal
void	handle_signal(int sig);

#endif
