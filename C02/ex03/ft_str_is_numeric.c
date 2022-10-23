/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:57:02 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 09:57:12 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (0);
		idx++;
	}
	return (1);
}
