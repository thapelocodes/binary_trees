#include "binary_trees.h"

/**
 * btic - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @idx: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete or if tree is NULL
 */
int btic(const binary_tree_t *tree, size_t idx, size_t size)
{
	if (!tree)
		return (1);

	if (idx >= size)
		return (0);

	return (btic(tree->left, 2 * idx + 1, size) &&
		btic(tree->right, 2 * idx + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (btic(tree, 0, size));
}
