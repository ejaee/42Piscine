/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:46:03 by choiejae          #+#    #+#             */
/*   Updated: 2022/03/01 02:21:07 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
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
	t_btree *node;

	node = btree_create_node("1\n");
	node->left = btree_create_node("2\n");
	node->right = btree_create_node("3\n");
	node->left->left = btree_create_node("4\n");
	node->left->right = btree_create_node("5\n");
	node->right->left = btree_create_node("6\n");
	node->right->right = btree_create_node("7\n");
	btree_apply_prefix(node, (void*)ft_putstr);
}
*/
