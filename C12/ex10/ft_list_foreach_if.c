/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:23:39 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/23 19:23:03 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, \
		void (*f)(void *), void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!(*cmp)(begin_list->data, data_ref))
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
/*
#include <unistd.h>
#include "../ex00/ft_create_elem.c"

void	ft_putstr(void *str)
{
	while (*(char*)str)
		write(1, (char*)str++, 1);
}

int	cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int main()
{
	t_list	*list;
	t_list	*head;

	list = ft_create_elem("mine");
	list->next = ft_create_elem("mine");
	list->next->next = ft_create_elem("safe");
	list->next->next->next = ft_create_elem("mine");
	list->next->next->next->next = ft_create_elem("mine");
	head = list;

	ft_list_foreach_if(head, ft_putstr, "safe", cmp);
	write(1, "\n", 1);
}
*/
