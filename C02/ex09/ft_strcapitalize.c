/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:58:56 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 10:02:26 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_upper(char c)
{
	c -= 32;
	return (c);
}

char	ft_lower(char c)
{
	c += 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ((str[idx] >= 97 && str[idx] <= 122)
			|| (str[idx] >= 65 && str[idx] <= 90)
			|| (str[idx] >= '0' && str[idx] <= '9'))
		{
			if (str[idx] >= 97 && str[idx] <= 122)
				str[idx] = ft_upper(str[idx]);
			idx++;
			while ((str[idx] >= 97 && str[idx] <= 122)
				|| (str[idx] >= 65 && str[idx] <= 90)
				|| (str[idx] >= '0' && str[idx] <= '9'))
			{
				if (str[idx] >= 65 && str[idx] <= 90)
					str[idx] = ft_lower(str[idx]);
				idx++;
			}
		}
		idx++;
	}
	return (str);
}
