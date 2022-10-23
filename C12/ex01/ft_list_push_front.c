/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:10:44 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/21 14:49:54 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (*begin_list)
	{
		new_node = ft_create_elem(data);
		new_node->next = *begin_list;
		*begin_list = new_node;
	}
	else
		*begin_list = ft_create_elem(data);
}
/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main()
{
	t_list **begin_list;
	t_list *list;
	list = ft_create_elem("1 : one");
	list->next = ft_create_elem("2 : two");
	begin_list = &list;
	ft_list_push_front(begin_list, "0 : zero");
	
	while (*begin_list)
	{
		ft_putstr((char*)(*begin_list)->data);
		*begin_list = (*begin_list)->next;
		write(1, "\n", 1);
	}
}
*/
