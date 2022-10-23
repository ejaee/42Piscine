/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:11:21 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/15 01:05:47 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	idx;

	idx = 2;
	if (nb > 1)
	{
		while (idx <= nb)
		{
			if (nb % idx == 0)
			{
				if (nb == idx)
					return (1);
				else
					return (0);
			}
			idx ++;
		}
	}
	return (0);
}
