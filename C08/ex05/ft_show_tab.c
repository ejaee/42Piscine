/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:24:36 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/20 22:47:23 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../ex04/ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		write(1, "8", 1);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write (1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		idx;

	idx = -1;
	while (par[++ idx].str)
	{
		ft_putnbr(par[idx].size);
		write(1, "\n", 1);
		ft_putstr(par[idx].str);
		write(1, "\n", 1);
		ft_putstr(par[idx].copy);
		write(1, "\n", 1);
	}
}
/*
#include "../ex04/ft_strs_to_tab.c"

int main(int ac, char **av)
{
	ft_show_tab(ft_strs_to_tab(ac, av));
}
*/
