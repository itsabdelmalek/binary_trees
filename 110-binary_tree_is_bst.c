#include "binary_trees.h"

/**
 * is_bst_recursive - Helper function to check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @prev: Pointer to the previously visited node's value.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_recursive(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_recursive(tree->left, prev))
		return (0);

	if (*prev != -1 && tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (is_bst_recursive(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = -1;

	if (tree == NULL)
		return (0);

	return (is_bst_recursive(tree, &prev));
}
