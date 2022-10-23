/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:20:09 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 15:20:14 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	count_file_size(char *argv)
{
	char	buffer;
	int		fd;
	int		size;

	size = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_error(argv);
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
