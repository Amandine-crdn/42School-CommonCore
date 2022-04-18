#include "../includes/philosophers.h"

int	write_error(char *mess, int code)
{
	write(2, mess, ft_strlen(mess));
	write(2, "\n", 1);
	return (code);
}
