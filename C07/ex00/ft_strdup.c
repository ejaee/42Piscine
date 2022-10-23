/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:55:08 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/14 13:18:59 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strdup(char *src)
{
	int		idx;
	char	*dup;

	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (0);
	idx = 0;
	while (src[idx])
	{
		dup[idx] = src[idx];
		idx ++;
	}
	dup[idx] = '\0';
	return (dup);
}
