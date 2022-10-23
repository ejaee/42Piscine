/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:52:26 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/21 15:30:44 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list)
	{
		if (!nbr)
			return (begin_list);
		nbr--;
		begin_list = begin_list->next;
	}
	return (0);
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
	t_list *list;
	list = ft_create_elem("one");
	list->next = ft_create_elem("two");
	list->next->next = ft_create_elem("three");
	list->next->next->next = ft_create_elem("four");
	list->next->next->next->next = ft_create_elem("five");
	ft_putstr((char*)ft_list_at(list, 0)->data);
	write(1, "\n", 1);
	ft_putstr((char*)ft_list_at(list, 1)->data);
	write(1, "\n", 1);
	ft_putstr((char*)ft_list_at(list, 2)->data);
	write(1, "\n", 1);
	ft_putstr((char*)ft_list_at(list, 3)->data);
	write(1, "\n", 1);
	ft_putstr((char*)ft_list_at(list, 4)->data);
	write(1, "\n", 1);
	return (0);
}
*/
