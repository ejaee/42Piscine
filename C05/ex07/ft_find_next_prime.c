/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:06:10 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/15 01:07:03 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	idx;

	idx = 2;
	while (idx <= nb / idx)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}
/*
int main(){
	int a = 2143473648;
	int b = 17;
	printf("%d보다 크거나 같은 소수 : %d\n", a, ft_find_next_prime(a));
	printf("%d보다 크거나 같은 소수 : %d\n", b, ft_find_next_prime(b));
	return 0;
}
*/
