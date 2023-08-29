#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t t_size = 0;

	if (tree)
	{
		t_size += 1;
		t_size += binary_tree_size(tree->left);
		t_size += binary_tree_size(tree->right);
	}
	return (t_size);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 * If tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete_recursive - Helper func to check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 * @index: Index of the current node.
 * @nodes_count: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree, size_t index,
		size_t nodes_count)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, nodes_count)
			&& is_complete_recursive(tree->right,
				2 * index + 2, nodes_count));
}
