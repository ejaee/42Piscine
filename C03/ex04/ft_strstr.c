/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:26:05 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/09 09:26:36 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	idx_d;
	int	idx_f;

	idx_d = 0;
	if (!to_find[0])
		return (str);
	while (str[idx_d])
	{
		idx_f = 0;
		while (str[idx_d + idx_f] == to_find[idx_f])
		{
			idx_f++;
			if (!to_find[idx_f])
				return (&str[idx_d]);
		}
		idx_d++;
	}
	return (0);
}
