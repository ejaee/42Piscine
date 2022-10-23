/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 04:40:41 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/23 15:26:54 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		temp = begin_list;
		begin_list = begin_list->next;
		(*free_fct)(temp->data);
		free(temp);
	}
}
/*
#include "../ex00/ft_create_elem.c"
#include <unistd.h>

void	free_fct(void *data)
{
	free(data);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main()
{
	t_list *list;
	t_list *full;
	t_list *free;

	list = ft_create_elem("11111");
	list->next = ft_create_elem("22222");
	list->next->next = ft_create_elem("33333");
	full = list;
	free = list;

	while (full)
	{
		ft_putstr((char*)(full->data));
		write(1, "\n", 1);
		full = full->next;
	}
	ft_list_clear(free, free_fct);
	ft_putstr((char*)free->data);
}
*/
