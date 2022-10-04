#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		j;
	size_t	len;

	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	j = -1;
	while (s2 && s2[++j])
		str[len++] = s2[j];
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!*s && !c)
		return ((char *)s);
	return (NULL);
}

char	*ft_select(char *buf, int *ret)
{
	int		i;
	char	*dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (ft_strchr(buf, '\n') != 0)
		*ret = 1;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_select2(char *buf)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(*dest) * (ft_strlen(buf) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (buf && buf[i])
		dest[j++] = buf[++i];
	dest[j] = 0;
	return (dest);
}
