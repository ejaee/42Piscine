/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:02:16 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/07 22:16:20 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dfs(int input, int nbr, int n, char *comb)
{
	int	idx;

	if (input == n)
	{
		idx = -1;
		while (++idx < n)
			write(1, &comb[idx], 1);
		if (comb[0] != (10 - n) + '0')
			write(1, ", ", 2);
	}
	else
	{
		while (nbr <= 9)
		{
			comb[input] = nbr + '0';
			dfs(input + 1, nbr + 1, n, comb);
			nbr++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	comb[11];

	dfs(0, 0, n, comb);
}
/*
int main()
{
	write(1, "\n--- size == 1 ---\n", 19);
	ft_print_combn(1);
	write(1, "\n--- size == 2 ---\n", 19);
	ft_print_combn(2);
	write(1, "\n--- size == 3 ---\n", 19);
	ft_print_combn(3);
	write(1, "\n--- size == 4 ---\n", 19);
	ft_print_combn(4);
	write(1, "\n--- size == 5 ---\n", 19);
	ft_print_combn(5);
	write(1, "\n--- size == 6 ---\n", 19);
	ft_print_combn(6);
	write(1, "\n--- size == 7 ---\n", 19);
	ft_print_combn(7);
	write(1, "\n--- size == 8 ---\n", 19);
	ft_print_combn(8);
	write(1, "\n--- size == 9 ---\n", 19);
	ft_print_combn(9);
	write(1, "\n--- size == 10 ---\n", 20);
	ft_print_combn(10);
}
*/
