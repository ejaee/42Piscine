/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:21:42 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 14:29:36 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

void	ft_put_error(char *str)
{
	while (*str)
		write(STDERR_FILENO, str ++, 1);
}

void	ft_set_error(char *prog_name, char *filename, int is_dir)
{
	ft_put_error(basename(prog_name));
	ft_put_error(": ");
	ft_put_error(filename);
	ft_put_error(": ");
	if (is_dir)
		ft_put_error("Is a directory");
	else
		ft_put_error(strerror(errno));
	ft_put_error("\n");
}

void	ft_display(int fd, int is_stdin)
{
	char	buffer;

	if (is_stdin)
	{
		while (read(STDIN_FILENO, &buffer, 1))
			write(STDOUT_FILENO, &buffer, 1);
	}
	while (read(fd, &buffer, 1))
		write(1, &buffer, 1);
}

void	ft_check_fd(int count, char **av)
{
	int		idx;
	int		fd;

	idx = 0;
	while (++ idx <= count)
	{
		if (av[idx][0] == '-' && av[idx][1] == '\0')
			ft_display(0, 1);
		else if (open(av[idx], O_DIRECTORY) == -1)
		{
			fd = open(av[idx], O_RDONLY);
			if (fd == -1)
				ft_set_error(av[0], av[idx], 0);
			else
				ft_display(fd, 0);
			close(fd);
		}
		else
		{
			ft_set_error(av[0], av[idx], 1);
			close(fd);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_display(0, 1);
	else
		ft_check_fd(ac - 1, av);
	return (0);
}
