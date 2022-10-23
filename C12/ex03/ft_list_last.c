/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:45:28 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/21 03:02:29 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list)
	{
		while (begin_list->next)
			begin_list = begin_list->next;
		return (begin_list);
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

void	ft_show_tab(t_list *key_list)
{
	ft_putstr((char*)key_list->data);
	write(1, "\n", 1);
}

int main()
{
	t_list **head;
	t_list	*list;
	t_list	*key_list;

	list = ft_create_elem("first");
	list->next = ft_create_elem("middle");
	list->next->next = ft_create_elem("end");
	head = &list;
	key_list = ft_list_last(list);
	ft_show_tab(key_list);
	return (0);
}
*/
