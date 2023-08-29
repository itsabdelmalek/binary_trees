#include "binary_trees.h"
#include "limits.h"

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
 * avl_func_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lowest: The value of the smallest node visited thus far.
 * @highest: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_func_helper(const binary_tree_t *tree, int lowest, int highest)
{
	size_t l_height, r_height, diff;

	if (tree != NULL)
	{
		if (tree->n < lowest || tree->n > highest)
			return (0);
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);
		diff = l_height > r_height ? l_height - r_height : r_height - l_height;
		if (diff > 1)
			return (0);
		return (avl_func_helper(tree->left, lowest, tree->n - 1) &&
			avl_func_helper(tree->right, tree->n + 1, highest));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_func_helper(tree, INT_MIN, INT_MAX));
}
