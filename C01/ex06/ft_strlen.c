/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:58:11 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/10 14:58:46 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		cnt;
	int		idx;

	cnt = 0;
	idx = 0;
	while (str[idx])
	{
		cnt ++;
		idx ++;
	}
	return (cnt);
}
