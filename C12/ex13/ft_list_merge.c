/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:04:49 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/23 19:23:35 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*head;

	if (*begin_list1)
	{
		head = *begin_list1;
		while (head->next)
			head = head->next;
		head->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
/*
#include <unistd.h>
#include "../ex00/ft_create_elem.c"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main()
{
	t_list	**list;
	t_list	*node;
	t_list	*merge;

	node = ft_create_elem("1");
	node->next = ft_create_elem("2");
	node->next->next = ft_create_elem("3");
	node->next->next->next = ft_create_elem("4");
	node->next->next->next->next = ft_create_elem("5");
	list = &node;

	merge = ft_create_elem("6");
	ft_list_merge(list, merge);

	while (node)
	{
		ft_putstr((char *)node->data);
		write(1, " ", 1);
		node = node->next;
	}
}
*/
