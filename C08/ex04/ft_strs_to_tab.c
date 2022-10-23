/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:25:33 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/14 16:19:20 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(char *str)
{
	int		idx;
	int		size;
	char	*dest;

	size = ft_strlen(str);
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (0);
	idx = -1;
	while (str[++ idx])
	{
		dest[idx] = str[idx];
	}
	dest[idx] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			idx;

	array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!array)
		return (0);
	idx = 0;
	while (idx < ac && av[idx])
	{
		array[idx].str = av[idx];
		array[idx].copy = ft_strdup(av[idx]);
		array[idx].size = ft_strlen(av[idx]);
		idx++;
	}
	array[idx].str = 0;
	return (array);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	int idx;
	struct s_stock_str	*arr;

	arr = ft_strs_to_tab(ac, av);
	idx = -1;
	while (++idx < ac)
	{
		printf ("size : %d\n", arr[idx].size);
		printf ("str : %s\n", arr[idx].str);
		printf ("cpy : %s\n", arr[idx].copy);
	}
	return (0);
}
*/
