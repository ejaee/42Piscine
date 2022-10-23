/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:54:19 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/05 18:19:41 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base, int len)
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

int	is_base(char c, char *base, int len)
{
	int	idx;

	idx = -1;
	while (++idx < len)
	{
		if (c == base[idx])
			return (idx);
	}
	return (-1);
}

int	start_atoi(char *str, char *base, int len)
{
	int	sign;
	int	res;

	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (is_base(*str, base, len) != -1)
	{	
		res = res * len + is_base(*str, base, len);
		str++;
	}
	return (sign * res);
}	

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	res;

	len = 0;
	while (base[len])
	{
		if (!check_base(base, len))
			return (0);
		len++;
	}
	if (len <= 1)
		return (0);
	res = start_atoi(str, base, len);
	return (res);
}
/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("     +--+13245sdff", "0123456789"));
}
*/
