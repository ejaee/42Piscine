/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:24:32 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/17 19:46:32 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	put_error(char *str)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
}

void	disp_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1))
		write(STDOUT_FILENO, &buffer, 1);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		put_error("File name missing.\n");
	else if (argc > 2)
		put_error("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			put_error("Cannot read file.\n");
		else
			disp_file(fd);
		close(fd);
	}
	return (0);
}
