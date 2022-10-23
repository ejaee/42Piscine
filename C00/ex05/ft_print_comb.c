/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:51:13 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/07 21:52:08 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dfs(int input, int nbr, char *comb)
{
	int	idx;

	if (input == 3)
	{
		idx = -1;
		while (++idx < 3)
			write(1, &comb[idx], 1);
		if (comb[0] != '7')
			write(1, ", ", 2);
	}
	else
	{
		while (nbr <= 9)
		{
			comb[input] = nbr + '0';
			dfs(input + 1, nbr + 1, comb);
			nbr++;
		}
	}
}

void	ft_print_comb(void)
{
	char	comb[4];

	dfs(0, 0, comb);
}
/*
int	main()
{
	ft_print_comb();
}
*/
