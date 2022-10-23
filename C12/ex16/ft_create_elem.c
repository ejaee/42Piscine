/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:02:38 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/20 23:18:51 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_show_tab(t_list *par)
{
	ft_putstr((char*)par->data);
	write (1, "\n", 1);
}

int main()
{
	char *data = "Hello World";
	t_list	*list;

	list = ft_create_elem((void*)data);
	ft_show_tab(list);
}
*/
