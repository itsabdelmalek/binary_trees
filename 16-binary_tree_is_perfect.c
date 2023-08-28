#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l_h = 0, r_h = 0;

		l_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l_h > r_h) ? l_h : r_h);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree)
	return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left == height_right)
	{
		if (!tree->left && !tree->right)
			return (1);
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	return (0);
}
