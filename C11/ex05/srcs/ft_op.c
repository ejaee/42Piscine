/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:01:40 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 18:36:19 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	get_op(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '*')
		return (2);
	if (op == '/')
		return (3);
	if (op == '%')
		return (4);
	else
		return (5);
}

void	ft_op(int a, char op, int b)
{
	void	(*f[5])(int a, int b);
	int		idx;

	f[0] = ft_sum;
	f[1] = ft_minus;
	f[2] = ft_multi;
	f[3] = ft_div;
	f[4] = ft_mod;
	idx = get_op(op);
	if (idx != 5)
		(f[idx])(a, b);
}
