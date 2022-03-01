/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:44:49 by acerdan           #+#    #+#             */
/*   Updated: 2022/03/01 11:30:01 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 4096
#endif

char	*ft_select(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
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

char	*ft_select2(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = NULL;
	while (*s && s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof(char) * ft_strlen(s) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (*s && s[i])
		str[j++] = s[++i];
	str[j] = 0;
	return (str);
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

char	*gnl(int fd)
{
	s_gnl	sgnl;

	sgnl.str = NULL;
	sgnl.line = NULL;
	sgnl.ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	while (sgnl.ret > 0)
	{
		sgnl.ret = read(fd, sgnl.buf, BUFFER_SIZE);
		sgnl.buf[sgnl.ret] = 0;
		sgnl.temp = sgnl.str;
		sgnl.str = ft_strjoin(sgnl.temp, sgnl.buf);
		free(sgnl.temp);
		if (ft_strchr(sgnl.str, '\n') == 1)
			break ;
	}
	sgnl.line = ft_select(sgnl.str);
	sgnl.temp = sgnl.str;
	sgnl.str = ft_select2(sgnl.temp);
	free(sgnl.temp);
	if (ft_check_return(sgnl.ret, &sgnl.str) == 0 && sgnl.line[0] == '\0')
		return (NULL);
	return (sgnl.line);
}
