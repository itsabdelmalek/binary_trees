#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t t_leaves = 0;

	if (tree)
	{
		t_leaves += (!tree->left && !tree->right) ? 1 : 0;
		t_leaves += binary_tree_leaves(tree->left);
		t_leaves += binary_tree_leaves(tree->right);
	}
	return (t_leaves);
}
