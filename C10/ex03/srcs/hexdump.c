/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:02:43 by juji              #+#    #+#             */
/*   Updated: 2022/01/31 15:02:51 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	init_global(char *argv0, char *argv2)
{
	s_global.hex = "0123456789abcdef";
	s_global.file_size = 0;
	s_global.idx = 0;
	s_global.fd = 0;
	s_global.program_name = argv0;
	count_file_size(argv2);
}

void	ft_hexdump(int last)
{
	if (last)
		print_address(s_global.file_size);
	else
	{
		print_address(s_global.idx);
		print_hex(s_global.buffer, ft_strlen(s_global.buffer));
		print_str(s_global.buffer, ft_strlen(s_global.buffer));
		init_buffer();
	}
	write(1, "\n", 1);
}

void	init_buffer(void)
{
	int	idx;

	idx = -1;
	while (++idx <= 16)
		s_global.buffer[idx] = 0;
}
