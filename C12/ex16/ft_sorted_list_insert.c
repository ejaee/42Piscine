/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:43:55 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/23 20:23:18 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*temp;
	t_list	*head;
	t_list	*move;

	head = *begin_list;
	while (head)
	{
		move = *begin_list;
		while (move->next)
		{
			if (cmp(move->data, move->next->data) > 0)
			{
				temp = move->data;
				move->data = move->next->data;
				move->next->data = temp;
			}
			move = move->next;
		}
		head = head->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*head;

	if (begin_list)
	{
		head = *begin_list;
		while (head->next)
			head = head->next;
		head->next = ft_create_elem(data);
		ft_list_sort(begin_list, cmp);
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

int	ft_strcmp(void *data1, void *data2)
{
	while (*(char*)data1 && *(char*)data1 == *(char*)data2)
	{
		data1++;
		data2++;
	}
	return (*(char*)data1 - *(char*)data2);
}

int main()
{
	t_list	**begin_list;
	t_list	*list;
	t_list	*list1;
	t_list	*list2;

	list = ft_create_elem("9");
	list->next = ft_create_elem("5");
	list->next->next = ft_create_elem("7");
	list->next->next->next = ft_create_elem("1");
	begin_list = &list;
	list1 = list;
	list2 = list;

	while (list1)
	{
		ft_putstr((char*)list1->data);
		write(1, "\n", 1);
		list1 = list1->next;
	}

	ft_sorted_list_insert(begin_list, (void*)"8", ft_strcmp);
	ft_sorted_list_insert(begin_list, (void*)"4", ft_strcmp);
	ft_sorted_list_insert(begin_list, (void*)"6", ft_strcmp);
	ft_sorted_list_insert(begin_list, (void*)"2", ft_strcmp);
	ft_sorted_list_insert(begin_list, (void*)"3", ft_strcmp);
	write(1, "---- update ----\n", 17);
	while (list2)
	{
		ft_putstr((char*)list2->data);
		write(1, "\n", 1);
		list2 = list2->next;
	}
}
*/
