/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:39 by juji              #+#    #+#             */
/*   Updated: 2022/01/31 14:59:11 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_error(char *file)
{
	ft_putstr(s_global.program_name);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
}

void	count_file_size(char *argv)
{
	char	buffer;
	int		fd;
	int		size;

	size = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		print_error(argv);
	}
	else
	{
		while (read(fd, &buffer, 1))
		{
			if (errno)
				return ;
			size++;
		}
		close(fd);
	}
	s_global.file_size = size;
}

int	ft_strlen(unsigned char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		;
	return (idx);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
