/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:15:58 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/20 11:16:22 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	is_op(char op)
{
	if (op == '+' || op == '-' || op == '*' \
			|| op == '/' || op == '%')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!is_op(av[2][0]) || (av[2][1] != '\0'))
		{
			write(1, "0\n", 2);
			return (0);
		}
		ft_op(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
		write(1, "\n", 1);
	}
	return (0);
}
