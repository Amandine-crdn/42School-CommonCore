#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 4096
#endif
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

int     ft_strlen(char *s)
{
    int i = 0;
    while (*s && s[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *temp, char *buf)
{
    int len;
    char *join;
    if (temp)
        len = ft_strlen(temp);
    if (buf)
        len += ft_strlen(buf);
    join = malloc(sizeof(char) * len + 1);
    if (!join)
        return (NULL);
    int i = 0;
    while (temp && temp[i])
    {
        join[i] = temp[i];
        i++;
    }
    int j = 0;
    while (buf && buf[j])
    {
        join[i + j] = buf[j];
        j++;
    }
    join[i + j] = 0;
    return (join);
}

char    *ft_select(char *s)
{  
    char *str = NULL;
    int i = 0;

    while (*s && s[i] && s[i] != '\n')
        i++;
    str = malloc(sizeof(char) * i + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (*s && s[i] && s[i] != '\n')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

char    *ft_select2(char *s)
{  
    char *str = NULL;
    int i = 0;

    while (*s && s[i] && s[i] != '\n')
        i++;
    str = malloc(sizeof(char) * ft_strlen(s) - i + 1);
    if (!str)
        return (NULL);
    int j = 0;
    while (*s && s[i])
    {
        str[j++] = s[++i];
    }
    str[j] = 0;
    return (str);
}

int     ft_strchr(char *buf, char c)
{
    int i = 0;
    while (*buf && buf[i] && buf[i] != c)
        i++;
    if (buf[i] == c)
        return (1);
    return (0);    
}

int	ft_check_return(int ret, char **str)
{
	if (ret == 0 && (*str)[0] == 0)
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	return (1);
}

char    *gnl(int fd)
{
    char *line = NULL;
    static char *str = NULL;
    ssize_t ret;
    char buf[BUFFER_SIZE + 1];
    char *temp;
    ret = 1;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
        return (NULL);
    
    while (ret > 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        buf[ret] = 0;
        temp = str;
        str = ft_strjoin(temp, buf);
        free(temp);
        if (ft_strchr(str, '\n') == 1)
            break;
    }
    line = ft_select(str);
    temp = str;
    str = ft_select2(temp);
    free(temp);
    if (ft_check_return(ret, &str) == 0 && line[0] == '\0')
        return (NULL);
    return (line);   
}

int main()
{
    int fd;
    char *line;
    char buf[BUFFER_SIZE + 1];
    fd = open("coucou.txt", O_RDONLY);

    while (line != NULL)
    {
        line = gnl(fd);
        printf("--- FINAL LINE = %s\n", line);
    }
    return (0);
}