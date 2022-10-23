/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:55:04 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/22 18:20:25 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!(*cmp)(begin_list->data, data_ref))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
/*
#include "../ex00/ft_create_elem.c"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{	
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main()
{
	t_list *list;
	t_list *find;

	list = ft_create_elem("<Personal Information>");
	list->next = ft_create_elem("ID");
	list->next->next = ft_create_elem("42seoul");
	list->next->next->next = ft_create_elem("PW");
	list->next->next->next->next = ft_create_elem("1234");
	find = ft_list_find(list, "PW", cmp);
	if (find)
		write(1, "---- find! ----\n", 17);
	while (find)
	{
		ft_putstr((char*)find->data);
		write(1, "\n", 1);
		find = find->next;
	}
}
*/
