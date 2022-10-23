/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:09:01 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 00:42:14 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		idx;
	int		cnt_up;
	int		cnt_down;

	idx = 0;
	cnt_up = 0;
	cnt_down = 0;
	while (idx < length - 1)
	{
		if (f(tab[idx + 1], tab[idx]) >= 0)
			cnt_up++;
		if (f(tab[idx + 1], tab[idx]) <= 0)
			cnt_down++;
		idx++;
	}
	if (cnt_up == idx || cnt_down == idx)
		return (1);
	return (0);
}
/*
int func(int a, int b)
{
	return (a - b);
}
*/
