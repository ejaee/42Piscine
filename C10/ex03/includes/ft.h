/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:04:04 by juji              #+#    #+#             */
/*   Updated: 2022/01/31 15:10:46 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

struct s_tool
{
	const char		*hex;
	int				file_size;
	int				idx;
	int				fd;
	char			*program_name;
	unsigned char	buffer[17];
} s_global;

void	count_file_size(char *argv);
void	print_error(char *file);
void	ft_putstr(char *str);
int		ft_strlen(unsigned char *str);
void	print_address(int nbr);
void	print_hex(unsigned char *p, unsigned int size);
void	print_str(unsigned char *p, int unsigned size);
void	init_buffer(void);
void	ft_hexdump(int last);
void	init_global(char *argv0, char *argv2);

#endif
