/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:56:19 by choiejae          #+#    #+#             */
/*   Updated: 2022/03/01 02:12:51 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
/*
#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
		write (1, s++, 1);
	write(1, "\n", 1);
}

int	main()
{
	t_btree	*node;

	node = btree_create_node("ejae");
	ft_putstr((char *)node->item);
}
*/
