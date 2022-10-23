/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:27:25 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/21 05:23:24 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}
/*
#include "../ex00/ft_create_elem.c"
#include <stdio.h>

int	main()
{
	t_list **head;
	t_list *list;
	list = ft_create_elem("1");
	list->next = ft_create_elem("2");
	list->next->next = ft_create_elem("3");
	head = &list;
	printf("%d NODE\n", ft_list_size(list));// ft_list_size(*head)	
}
*/
