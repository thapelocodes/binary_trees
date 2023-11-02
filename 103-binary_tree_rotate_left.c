#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left-rotates a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tp, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	tp = tree->right;
	tmp = tp->left;
	tp->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = tp;
	tp->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = tp;
		else
			tmp->right = tp;
	}

	return (tp);
}
