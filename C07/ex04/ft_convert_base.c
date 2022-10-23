/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:32:02 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/05 17:42:51 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_size(int nbr, int type);
char	*ft_itoa_base(int nbr, char *base, int len);

int	is_base(char *base, int len)
{
	int	idx;

	if (base[len] == ' ' || (9 <= base[len] && base[len] <= 13))
		return (0);
	if (base[len] == '-' || base[len] == '+')
		return (0);
	idx = -1;
	while (++idx < len)
	{
		if (base[idx] == base[len])
			return (0);
	}
	return (1);
}

int	is_exist(char c, char *base_from)
{
	int	i;

	i = -1;
	while (base_from[++i])
	{
		if (c == base_from[i])
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base_from, int from_len)
{
	int	idx;
	int	sign;
	int	res;
	int	cnt;

	res = 0;
	sign = 1;
	idx = 0;
	while (nbr[idx] == ' '
		|| (9 <= nbr[idx] && nbr[idx] <= 13))
		idx++;
	while (nbr[idx] == '+' || nbr[idx] == '-')
	{
		if (nbr[idx] == '-')
			sign *= -1;
		idx++;
	}
	cnt = 0;
	while (is_exist(nbr[idx], base_from) != -1)
	{
		res = res * from_len + (is_exist(nbr[idx], base_from));
		cnt++;
		idx++;
	}
	return (sign * res);
}

int	check_base(char *base)
{
	int	len;

	len = 0;
	while (base[len])
	{
		if (!is_base(base, len))
			return (0);
		len++;
	}
	if (len <= 1)
		return (0);
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		convert_num;
	int		from_len;
	int		to_len;
	char	*res;

	to_len = 0;
	from_len = check_base(base_from);
	to_len = check_base(base_to);
	if (!from_len || !to_len)
		return (0);
	convert_num = ft_atoi_base(nbr, base_from, from_len);
	res = ft_itoa_base(convert_num, base_to, to_len);
	return (res);
}
/*
#include <stdio.h>

int main()
{
	char *res = ft_convert_base("-12", "0123456789", "01");

	printf("res : %s\n", res);
	printf("res : %s\n", ft_convert_base("mrdoc", "mrd", "mrdoc"));
	printf("res : %s\n", ft_convert_base("12", "0123456789", "01"));
	printf("res : %s\n", ft_convert_base("-2147483648", "0123456789", "01"));
}
*/
