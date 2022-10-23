/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:16:31 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/23 19:22:44 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	t_list	*cur;
	t_list	*temp;

	head = *begin_list;
	while (head)
	{
		cur = *begin_list;
		while (cur->next)
		{
			if (cmp(cur->data, cur->next->data) > 0)
			{
				temp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = temp;
			}
			cur = cur->next;
		}
		head = head->next;
	}
}
/*
#include "../ex00/ft_create_elem.c"
#include <unistd.h>

int	ft_strcmp(void *s1, void *s2)
{
	while (*(char*)s1 && *(char*)s1 == *(char*)s2)
	{	
		s1++;
		s2++;
	}
	return (*(char*)s1 - *(char*)s2);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main()
{
	t_list	**begin_list;
	t_list	*list;
	t_list	*list2;

	list = ft_create_elem("9");
	list->next = ft_create_elem("5");
	list->next->next = ft_create_elem("1");
	list->next->next->next = ft_create_elem("3");
	list->next->next->next->next = ft_create_elem("7");
	list2 = list;
	begin_list = &list2;

	while (list)
	{
		ft_putstr((char*)list->data);
		write(1, "\n", 1);
		list = list->next;
	}
	write(1, "----sorting----\n", 16);

	ft_list_sort(begin_list, ft_strcmp);
	while (list2)
	{
		ft_putstr((char*)list2->data);
		write(1, "\n", 1);
		list2 = list2->next;
	}
}
*/
