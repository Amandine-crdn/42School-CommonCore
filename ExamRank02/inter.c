#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int ascii[128];
	int i = 0;
	while (i < 128)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	while (*s1 && s1[i])
	{
		if (ascii[(int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			ascii[(int)s1[i]] = 1;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
