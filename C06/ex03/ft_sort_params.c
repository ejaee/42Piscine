#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (!*s2)
		return (0);
	return (-*s2);
}

int main(int argc, char *argv[])
{
	int	idx;
	int	jdx;
	char *temp;

	idx = 1;
	while (idx < argc - 1)
	{
		jdx = idx + 1;
		while (jdx < argc)
		{
			if (ft_strcmp(argv[idx], argv[jdx]) > 0)
			{
				temp = argv[idx];
				argv[idx] = argv[jdx];
				argv[jdx] = temp;
			}
			jdx++;
		}
		idx++;
	}
	idx = 1;
	while (idx < argc)
	{
		ft_putstr(argv[idx]);
		write (1, "\n", 1);
		idx++;
	}
	return (0);
}
