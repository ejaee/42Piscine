/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:46:42 by juji              #+#    #+#             */
/*   Updated: 2022/02/21 14:42:42 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list)
	{
		while ((*begin_list)->next)
			*begin_list = (*begin_list)->next;
		(*begin_list)->next = ft_create_elem(data);
	}
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
	t_list	*list;
	t_list	*start;

	list = ft_create_elem("1");
	list->next = ft_create_elem("2");
	list->next->next = ft_create_elem("3");
	begin_list = &list;
	start = list;
	ft_list_push_back(begin_list, "4");

	while (start)
	{
		ft_putstr((char*)start->data);
		write(1, "\n", 1);
		start = start->next;
	}
}
*/
