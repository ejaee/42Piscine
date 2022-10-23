/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:19:37 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 15:19:47 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

struct s_tool
{
	char	*program_name;
	char	*buffer;
	int		fd;
	int		buffer_size;
	int		file_size;
} s_global;

void	use_stdin(void);
void	print_error(char *file);
void	ft_putstr(char *str);
void	count_file_size(char *argv);
void	display_file(int fd);
int		ft_atoi(char *str);
#endif
