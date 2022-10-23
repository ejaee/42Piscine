/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:57:59 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/22 13:22:45 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}
/*
#include <unistd.h>
#include "../ex00/ft_create_elem.c"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ptr_putstr(void *str)
{
	while (*(char*)str)
		write(1, (char*)str++, 1);
	write(1, " ", 1);
}

int main()
{
	t_list	*head;
	t_list	*std;
	t_list	*std2;

	head = ft_create_elem("1");
	head->next = ft_create_elem("2");
	head->next->next = ft_create_elem("3");
	head->next->next->next = ft_create_elem("4");
	head->next->next->next->next = ft_create_elem("5");
	std = head;
	std2 = head;

	while (std)
	{
		ft_putstr((char*)std->data);
		std = std->next;
		write(1, " ", 1);
	}

	write(1, "\n", 1);
	ft_list_foreach(std2, ptr_putstr);
}
*/
