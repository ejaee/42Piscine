/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:20:28 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 15:20:32 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	display_file(int fd)
{
	char	buffer;
	int		readed;
	int		offset;

	offset = s_global.file_size - s_global.buffer_size;
	readed = 0;
	while (readed < offset)
	{
		read(fd, &buffer, 1);
		if (errno)
			return ;
		readed++;
	}
	if (readed == offset)
	{
		while (read(fd, &buffer, 1))
		{
			if (errno)
				return ;
			write(1, &buffer, 1);
		}
	}
}
