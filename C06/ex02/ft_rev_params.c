#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int idx;

	idx = argc - 1;
	while (0 < idx)
	{
		ft_putstr(argv[idx]);
		write (1, "\n", 1);
		idx--;
	}
	return (0);
}
