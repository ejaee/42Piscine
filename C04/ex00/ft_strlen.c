/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:09:19 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/06 10:07:12 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}
/*
#include <stdio.h>
int main()
{
	char *arr = "0123"; // 0은 문자 48이기 때문에 안잡힌다

	printf("%d\n", ft_strlen(arr));
}
*/
