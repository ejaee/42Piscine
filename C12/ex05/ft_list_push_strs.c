/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 04:10:34 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/21 14:47:37 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		idx;
	t_list	*new_node;
	t_list	*temp;

	idx = 0;
	temp = ft_create_elem(strs[idx]);
	while (++idx <= size)
	{
		new_node = ft_create_elem(strs[idx]);
		new_node->next = temp;
		temp = new_node;
	}
	return (new_node);
}
/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	int size = ac - 1;
	t_list *list;

	if (ac == 1)
		return (0);
	list = ft_list_push_strs(size, av);
	while (list)
	{
		ft_putstr((char*)list->data);
		write(1, "\n", 1);
		list = list->next;
	}
}
*/
