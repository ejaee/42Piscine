/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:30:04 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/24 16:13:51 by choiejae         ###   ########.fr       */
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

void	ft_sorted_list_merge(t_list **begin_list1, \
		t_list *begin_list2, int (*cmp)())
{
	t_list	*head;

	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		head = *begin_list1;
		while (head->next)
			head = head->next;
		head->next = begin_list2;
	}
	ft_list_sort(begin_list1, cmp);
}
/*
#include <unistd.h>
#include "../ex00/ft_create_elem.c"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strcmp(void *s1, void *s2)
{
	while (*(char*)s1 && *(char*)s1 == *(char*)s2)
	{
		s1++;
		s2++;
	}
	return (*(char*)s1 - *(char*)s2);
}

int	main()
{
	t_list	**begin_list;
	t_list	*list1;
	t_list	*list2;
	
	list1 = ft_create_elem("9");
	list1->next = ft_create_elem("1");
	list1->next->next = ft_create_elem("3");
	list1->next->next->next = ft_create_elem("7");
	list1->next->next->next->next = ft_create_elem("5");

	list2 = ft_create_elem("4");
	list2->next = ft_create_elem("8");
	list2->next->next = ft_create_elem("6");
	list2->next->next->next = ft_create_elem("0");
	list2->next->next->next->next = ft_create_elem("2");
	begin_list = &list1;

	ft_sorted_list_merge(begin_list, list2, ft_strcmp);
	while (list1)
	{
		ft_putstr(list1->data);
		write(1, " ", 1);
		list1 = list1->next;
	}
}
*/
