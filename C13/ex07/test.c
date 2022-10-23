#include "ft_btree.h"

struct s_g {
	int	level;
	int	first;
} s_global = {0, 1};

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
	{
		s_global.level--;
		return ;
	}
	applyf(root->item, s_global.level, s_global.first);
	s_global.level++;
	btree_apply_by_level(root->left, applyf);
	if (root->left)
		s_global.first = 0;
	s_global.level++;
	btree_apply_by_level(root->right, applyf);
	s_global.level--;
}
#include <stdio.h>
void	ft_display(void *item, int current_level, int is_first_elem)
{
	printf("[Level = %d] (first = %d) %s\n", current_level, is_first_elem, (char *)item);
}
#include <unistd.h>
#include "../ex00/btree_create_node.c"
void    ft_putstr(char *str)
{
        while (*str)
                write(1, str++, 1);
}
int     main(void)
{
        t_btree *node;
        node = btree_create_node("root\n");
        node->left = btree_create_node("1_left\n");
        node->right = btree_create_node("1_right\n");
        node->left->left = btree_create_node("2_left_left\n");
        node->left->right = btree_create_node("2_left_right\n");
        node->right->left = btree_create_node("2_right_left\n");
        node->right->right = btree_create_node("2_right_right\n");
		btree_apply_by_level(node, ft_display);
}
