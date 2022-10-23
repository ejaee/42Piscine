/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:07:23 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/23 19:22:15 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*std;
	t_list	*move;
	t_list	*temp;

	std = begin_list;
	while (std)
	{
		move = std->next;
		while (move)
		{
			temp = std->data;
			std->data = move->data;
			move->data = temp;
			move = move->next;
		}
		std = std->next;
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

int	main()
{
	t_list	*list;
	t_list  *std;
	t_list  *rev;

	list = ft_create_elem("9");
	list->next = ft_create_elem("7");
	list->next->next = ft_create_elem("5");
	list->next->next->next = ft_create_elem("3");
	list->next->next->next->next = ft_create_elem("1");
	std = list;
	rev = list;

	while (std)
	{
		ft_putstr((char*)std->data);
		write(1, " ", 1);
		std = std->next;
	}

	ft_list_reverse_fun(list);
	write(1, "\n----reverse list----\n", 22);

	while (rev)
	{
		ft_putstr((char*)rev->data);
		write(1, " ", 1);
		rev = rev->next;
	}
}
*/
