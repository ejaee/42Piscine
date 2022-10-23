/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:57:55 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/22 01:19:36 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	cur = *begin_list;
	prev = 0;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*begin_list = prev;
}
/*
#include "../ex00/ft_create_elem.c"
#include <unistd.h>

void	ft_putstr(char* str)
{
	while (*str)
		write(1, str++, 1);
}

int	main()
{
	t_list	**begin_list;
	t_list	*list;
	t_list	*std;
	t_list	*rev;

	list = ft_create_elem("1");
	list->next = ft_create_elem("2");
	list->next->next = ft_create_elem("3");
	list->next->next->next = ft_create_elem("4");
	begin_list = &list;
	std = list;
	rev = list;

	ft_putstr("\n---std node---\n");
	while (std)
	{
		ft_putstr((char*)std->data);
		std = std->next;
		write(1, "\n", 1);
	}

	ft_list_reverse(&rev);
	ft_putstr("\n---rev node---\n");
	while (rev)
	{
		ft_putstr((char*)rev->data);
		rev = rev->next;
		write(1, "\n", 1);
	}
}
*/
