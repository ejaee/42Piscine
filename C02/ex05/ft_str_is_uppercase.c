/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:57:35 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 09:57:45 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 'A' || str[idx] > 'Z')
			return (0);
		idx++;
	}
	return (1);
}
