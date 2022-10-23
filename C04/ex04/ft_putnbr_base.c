/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:25:53 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/06 10:18:05 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	go_convert(long long nbr, char *base, int type)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < type)
	{
		ft_putchar(base[nbr]);
		return ;
	}
	else
	{
		go_convert(nbr / type, base, type);
		go_convert(nbr % type, base, type);
	}
}

int	check_base(char *base, int cnt)
{
	int	idx;

	if (base[cnt] == '-' || base[cnt] == '+')
		return (0);
	idx = 0;
	while (idx < cnt)
	{
		if (base[idx] == base[cnt])
			return (0);
		idx++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	cnt;

	cnt = 0;
	while (base[cnt])
	{
		if (!check_base(base, cnt))
			return ;
		cnt++;
	}
	if (cnt <= 1)
		return ;
	go_convert(nbr, base, cnt);
}
/*
int	main()
{
	ft_putnbr_base(1234567890, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(65536, "01");
	write(1, "\n", 1);
	ft_putnbr_base(100000000, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(2147438647, "0123456");
	write(1, "\n", 1);
	ft_putnbr_base(-2147438648, "01234");
	write(1, "\n", 1);
	ft_putnbr_base(2147438647, "0123456789ABCDEFGHIJKLMNOPQ");
	write(1, "\n", 1);
}
*/
