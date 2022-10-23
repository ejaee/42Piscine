/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:17:59 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/15 01:08:34 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_abs(int a, int b)
{
	if (a - b >= 0)
		return (a - b);
	else
		return (b - a);
}

int	ft_promising(int chess[10], int row, int col)
{
	int	idx;

	idx = 0;
	while (idx < row)
	{
		if (chess[idx] == col || row - idx == ft_abs(col, chess[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void	ft_reculsive_puzzle(int chess[10], int *result, int row)
{
	int	idx;
	int	col;

	if (row == 10)
	{	
		(*result)++;
		idx = 0;
		while (idx < 10)
			ft_putchar(chess[idx++] + '0');
		ft_putchar('\n');
	}
	else
	{
		col = 0;
		while (col < 10)
		{
			if (ft_promising(chess, row, col))
			{	
				chess[row] = col;
				ft_reculsive_puzzle(chess, result, row + 1);
			}
			col ++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		chess[10];
	int		result;
	int		idx;

	idx = 0;
	result = 0;
	while (idx < 10)
	{
		chess[idx] = 0;
		idx++;
	}
	ft_reculsive_puzzle(chess, &result, 0);
	return (result);
}
/*
#include <stdio.h>

int	main(){
	printf("%d\n", ft_ten_queens_puzzle());
	return 0;
}
*/
