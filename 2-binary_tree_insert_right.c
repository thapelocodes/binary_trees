#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another
 * @parent: pointer to the parent of the new node
 * @value: value to store in the new node
 *
 * Return: a pointer to the new node or NULL on failure or if parent is NULL
 *
 * Description: if parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	parent->right = node;

	return (node);
}
