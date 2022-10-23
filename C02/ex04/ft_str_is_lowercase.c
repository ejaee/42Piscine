/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:57:17 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 09:57:23 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 'a' || str[idx] > 'z')
			return (0);
		idx++;
	}
	return (1);
}
