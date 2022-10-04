#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_select(char *buf, int *ret);
char	*ft_select2(char *buf);
int		ft_check_return(int ret, char **str);
int		ft_ckeck_error(int fd, char **line);
size_t	ft_strlen(const char *s);
int		get_next_line(int fd, char **line);
int		ft_ret_value(int ret, int fd, char *buf);

#endif
