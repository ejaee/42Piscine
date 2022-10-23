/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:06:04 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/14 13:21:25 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		size;
	int		*buffer;
	int		idx;

	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	buffer = malloc(sizeof(int) * size);
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	idx = 0;
	while (idx < size)
	{
		buffer[idx] = min + idx;
		idx ++;
	}
	*range = buffer;
	return (size);
}
/*
#include <stdio.h>
int	main(){
	int *arr;
	int size = ft_ultimate_range(&arr, -10, -2);
	int idx = 0;

	while (size--)
	{
		printf("%d\n", arr[idx++]);
	}
	return 0;
}
*/
