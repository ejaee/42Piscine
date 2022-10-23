/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:24:43 by juji              #+#    #+#             */
/*   Updated: 2022/01/31 15:03:29 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	init_global(argv[0], argv[2]);
	if (argc > 2 && (argv[1][0] == '-' && argv[1][1] == 'C'))
	{
		argv += 2;
		while (argc > 2)
		{
			s_global.fd = open(*argv, O_RDONLY);
			if (s_global.fd == -1)
				print_error(*argv);
			else
			{
				while (read(s_global.fd, s_global.buffer, 16))
				{
					if (errno)
						return (0);
					ft_hexdump(0);
					s_global.idx += 16;
				}
				close(s_global.fd);
			}
			argc--;
			argv++;
		}
		ft_hexdump(1);
	}
}
