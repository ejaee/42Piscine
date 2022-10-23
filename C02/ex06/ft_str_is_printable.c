/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:57:52 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 09:57:57 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 32 || str[idx] > 126)
			return (0);
		idx++;
	}
	return (1);
}
