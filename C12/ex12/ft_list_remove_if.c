/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:22:52 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/28 09:27:19 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_free(t_list *cur, void (*free_fct)(void*))
{
	free_fct(cur->data);
	free(cur);
}

void	ft_list_remove_if(t_list **begin_list, \
		void *data_ref, int (*cmp)(), void (*free_fct)(void*))
{
	t_list	*cur;
	t_list	*prev;

	cur = *begin_list;
	prev = 0;
	while (cur)
	{
		if (!(*cmp)(cur->data, data_ref))
		{
			if (!prev)
				*begin_list = cur->next;
			else
				prev->next = cur->next;
			ft_free(cur, free_fct);
			if (!prev)
				cur = *begin_list;
			else
				cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
/*
#include "../ex00/ft_create_elem.c"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	free_fct(void *data)
{
	write (1, "remove : ", 9);
	ft_putstr((char *)data);
	write(1, "\n", 1);
	data = 0;
}

int	main()
{
	t_list *list;
	t_list *update;

	list = ft_create_elem("11111");
	list->next = ft_create_elem("22222");
	list->next->next = ft_create_elem("11111");
	list->next->next->next = ft_create_elem("22222");
	list->next->next->next->next = ft_create_elem("11111");
	update = list;

	while (list)
	{
		ft_putstr((char*)list->data);
		write(1, " ", 1);
		list = list->next;
	}
	write(1, "\n", 1);
	ft_list_remove_if(&update, (void *)"11111", cmp, free_fct);
	while (update)
	{
		ft_putstr((char *)update->data);
		write(1, " ", 1);
		update = update->next;
	}
}
*/
