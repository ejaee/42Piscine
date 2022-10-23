/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:49:44 by choiejae          #+#    #+#             */
/*   Updated: 2022/03/12 16:57:08 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	void	*find;

	find = 0;
	if (root)
	{
		find = btree_search_item(root->left, data_ref, cmpf);
		if (!find && !cmpf(root->item, data_ref))
			find = root->item;
		if (!find)
			find = btree_search_item(root->right, data_ref, cmpf);
	}
	return (find);
}

/*
#include <unistd.h>
#include "../ex00/btree_create_node.c"

int		ft_strcmp(char *s1, char *s2)
{
	while(*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int main()
{
	t_btree *node;
	void	*a;

	node = btree_create_node("1");
	node->left = btree_create_node("2");
	node->right = btree_create_node("3");
	node->left->left = btree_create_node("4");
	node->left->right = btree_create_node("5");
	node->right->left = btree_create_node("6");
	node->right->right = btree_create_node("7");
	a = btree_search_item(node, "6", (void*)ft_strcmp);
	ft_putstr(a);
}
*/
