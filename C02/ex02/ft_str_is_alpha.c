/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:55:57 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 09:56:55 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char	*str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ((str[idx] < 'A' || str[idx] > 'Z')
			&& (str[idx] < 'a' || str[idx] > 'z'))
			return (0);
		idx++;
	}
	return (1);
}
