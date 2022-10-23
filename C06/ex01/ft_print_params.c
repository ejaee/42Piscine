#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int main(int argc, char *argv[])
{
	int idx;

	idx = 1;
	while (idx < argc)
	{
		ft_putstr(argv[idx]);
		write (1, "\n", 1);
		idx++;
	}
	return 0;
}
