/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump_detail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:00:13 by juji              #+#    #+#             */
/*   Updated: 2022/01/31 15:01:23 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_address(int nbr)
{
	unsigned int	address[7];
	unsigned int	idx;
	unsigned int	jdx;

	idx = 0;
	jdx = 8;
	if (nbr == 0)
		while (jdx--)
			write(1, "0", 1);
	else
	{
		while (nbr)
		{
			address[idx] = nbr % 16;
			nbr /= 16;
			idx++;
		}
		jdx = 8 - idx;
		while (jdx-- > 0)
			write(1, "0", 1);
		while (idx > 0)
			write(1, &s_global.hex[address[--idx]], 1);
	}
	write(1, "  ", 2);
}

void	print_hex(unsigned char *p, unsigned int size)
{
	unsigned int	idx;
	unsigned int	jdx;

	idx = 0;
	jdx = 0;
	while ((jdx < 16) && (idx + jdx < size))
	{
		write(1, &s_global.hex[(*(p + idx + jdx) / 16) % 16], 1);
		write(1, &s_global.hex[*(p + idx + jdx) % 16], 1);
		write(1, " ", 1);
		if (jdx == 7)
			write(1, " ", 1);
		jdx++;
	}
	if (jdx <= 7)
		write(1, " ", 1);
	while (jdx < 16)
	{
		write(1, "   ", 3);
		jdx++;
	}
	write(1, " ", 1);
}

void	print_str(unsigned char *p, int unsigned size)
{
	unsigned int	idx;
	unsigned int	jdx;

	idx = 0;
	jdx = 0;
	write(1, "|", 1);
	while ((jdx < 16) && (idx + jdx < size))
	{	
		if (p[idx + jdx] >= 32 && p[idx + jdx] <= 126)
			write(1, &p[(idx + jdx)], 1);
		else
			write(1, ".", 1);
		jdx++;
	}
	write(1, "|", 1);
}
