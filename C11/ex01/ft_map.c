/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:00:54 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/18 23:10:08 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		idx;
	int		*applied_tab;

	applied_tab = malloc(sizeof(int) * length + 1);
	if (!applied_tab)
		return (0);
	idx = -1;
	while (++idx < length)
		applied_tab[idx] = (*f)(tab[idx]);
	return (applied_tab);
}
/*
#include <unistd.h>
int func(int a)
{
	return (a * 3);
}
void	ft_putnbr(int nb)
{
	char	c;
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		write(1, "8", 1);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
int main(void)
{
	int	idx;
	int tab[10];
	int *new;
	idx = -1;
	while (++idx < 10)
		tab[idx] = idx;
	new = ft_map(tab, 10, &func);
	idx = -1;
	while (++idx < 10)
		ft_putnbr(new[idx]);
}
*/
