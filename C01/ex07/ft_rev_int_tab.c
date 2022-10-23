/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:56:44 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/10 14:57:26 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		idx;
	int		tmp;
	int		rev;

	idx = 0;
	rev = size - 1;
	while (idx < rev)
	{
		tmp = tab[idx];
		tab[idx] = tab[rev];
		tab[rev] = tmp;
		idx ++;
		rev --;
	}
}
