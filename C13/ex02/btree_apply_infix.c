/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_inwqfix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:22:08 by choiejae          #+#    #+#             */
/*   Updated: 2022/03/01 02:30:51 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}
/*
#include <unistd.h>
#include "../ex00/btree_create_node.c"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main()
{
	t_btree	*node;

	node = btree_create_node("1\n");
	node->left = btree_create_node("2\n");
	node->right = btree_create_node("3\n");
	node->left->left = btree_create_node("4\n");
	node->left->right = btree_create_node("5\n");
	node->right->left = btree_create_node("6\n");
	node->right->right = btree_create_node("7\n");
	btree_apply_infix(node, (void *)ft_putstr);
}
*/
