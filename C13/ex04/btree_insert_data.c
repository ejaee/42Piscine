/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:18:13 by choiejae          #+#    #+#             */
/*   Updated: 2022/03/13 09:04:28 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else if (cmpf((*root)->item, item) < 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
/*
#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	btree_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;

	applyf(root->item);
	btree_prefix(root->left, applyf);
	btree_prefix(root->right, applyf);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main()
{
	t_btree	*node;

	node = 0;		// error!!!!!!!!
	btree_insert_data(&node, "5", (void *)ft_strcmp);
	btree_insert_data(&node, "3", (void *)ft_strcmp);
	btree_insert_data(&node, "1", (void *)ft_strcmp);
	btree_insert_data(&node, "4", (void *)ft_strcmp);
	btree_insert_data(&node, "2", (void *)ft_strcmp);
	btree_prefix(node, (void *)ft_putstr);
}
*/
