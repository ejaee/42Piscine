/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:21:57 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 15:21:59 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	use_stdin(void)
{
	char	buffer;

	while (read(0, &buffer, 1))
		;
}

void	print_error(char *file)
{
	ft_putstr((char *)s_global.program_name);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 1)
	{
		use_stdin();
		return (0);
	}
	if (argc == 4)
	{
		s_global.program_name = argv[0];
		count_file_size(argv[3]);
		s_global.buffer_size = ft_atoi(argv[2]);
		fd = open(argv[3], O_RDONLY);
		if (fd == -1)
			print_error(argv[3]);
		else
		{
			if (argv[1][0] == '-' && (argv[1][1] == 'c' || argv[1][1] == 'C'))
				display_file(fd);
		}
		close(fd);
	}
	return (0);
}
