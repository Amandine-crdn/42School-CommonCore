#include "get_next_line.h"

int	ft_ret_value(int ret, int fd, char *buf)
{
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = 0;
	return (ret);
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

int	ft_ckeck_error(int fd, char **line)
{
	if ((fd < 0 || fd > 1023) || !line || BUFFER_SIZE <= 0)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*str = NULL;
	char		*temp;

	ret = BUFFER_SIZE;
	if (ft_ckeck_error(fd, line) == -1)
		return (-1);
	while (ret > 0)
	{
		ret = ft_ret_value(ret, fd, buf);
		if (ret == -1)
			return (-1);
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	*line = ft_select(str, &ret);
	temp = str;
	str = ft_select2(temp);
	free(temp);
	return (ft_check_return(ret, &str));
}
