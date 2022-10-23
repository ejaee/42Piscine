/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:31:38 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/05 14:31:34 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_size(int nbr, int type)
{
	int	cnt;

	cnt = 0;
	if (nbr < 0)
	{
		cnt = 1;
		nbr *= -1;
	}
	while (nbr >= 0)
	{
		nbr /= type;
		cnt++;
		if (nbr == 0)
			break ;
	}
	return (cnt);
}

void	go_malloc(char **res, char **stack, int size)
{
	*res = malloc(sizeof(char) * (size + 1));
	*stack = malloc(sizeof(char) * (size + 1));
}

void	minus(char **res, int *nbr, int *j)
{
	*res[0] = '-';
	*j = 1;
	*nbr *= -1;
}

char	*ft_itoa_base(int nbr, char *base, int len)
{
	int		idx;
	int		j;
	int		size;
	char	*res;
	char	*stack;

	size = check_size(nbr, len);
	go_malloc(&res, &stack, size);
	j = 0;
	if (nbr < 0)
		minus(&res, &nbr, &j);
	idx = 0;
	while (nbr >= 0)
	{
		stack[idx++] = base[nbr % len];
		nbr /= len;
		if (nbr == 0)
			break ;
	}
	while (j < size)
		res[j++] = stack[--idx];
	res[j] = '\0';
	return (res);
}
