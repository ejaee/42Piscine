/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:02:07 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/15 01:02:29 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	rst;

	rst = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	while (nb)
	{
		rst *= nb;
		nb --;
	}
	return (rst);
}
