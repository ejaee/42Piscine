/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:08:50 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/05 14:00:09 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		idx;
	int		*arr;

	idx = 0;
	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		arr[idx] = min;
		min ++;
		idx ++;
	}
	arr[idx] = '\0';
	return (arr);
}
/*
#include <stdio.h>
int	main(){
	int *test;

	test = ft_range(-5, -3);
	
	while (*test){
		printf ("%d", *test);
		test++;
	}
	return 0;
}
*/
