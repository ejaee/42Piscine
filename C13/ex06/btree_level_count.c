/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:05:51 by choiejae          #+#    #+#             */
/*   Updated: 2022/03/13 10:29:31 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	if (root)
	{
		if (btree_level_count(root->left) > btree_level_count(root->right))
			return (btree_level_count(root->left) + 1);
		return (btree_level_count(root->right) + 1);
	}
	return (0);
}
/******************************************************
int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (root)
	{
		count = ft_max(btree_level_count(root->left), \
				btree_level_count(root->right));
		return (count + 1);
	}
	return (0);
}
******************************************************/

/******************************************************
int	btree_level_count(t_btree *root)
{
	int		count_left;
	int		count_right;

	if (root)
	{
		count_left = btree_level_count(root->left);
		count_right = btree_level_count(root->right);
		if (count_left > count_right)
			return (count_left + 1);
		else
			return (count_right + 1);
	}
	else
		return (0);
}
******************************************************/
/*
#include "../ex00/btree_create_node.c"
#include <unistd.h>

void	ft_putnbr(int	nb)
{
	char c;

	if (nb == -2147483548)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb/10);
		ft_putnbr(nb%10);
	}
}

int	main()
{
	t_btree	*node;

	node = btree_create_node("1");
	node->left = btree_create_node("2");
	node->right = btree_create_node("2");
	node->left->right = btree_create_node("3");
	node->right->left = btree_create_node("3");
	node->right->right = btree_create_node("3");
	node->right->left->right = btree_create_node("4");
	node->right->left->right->left = btree_create_node("5");
	ft_putnbr(btree_level_count(node));
}
*/
