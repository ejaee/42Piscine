/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:15:26 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 18:30:44 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_sum(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_minus(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_multi(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_div(int a, int b)
{
	if (!b)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void	ft_mod(int a, int b)
{
	if (!b)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}
