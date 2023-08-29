#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_is_avl(tree) != -1);
}

/**
 * bst_is_avl - Checks if a binary search tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: Height of the tree if it's a valid AVL Tree, -1 otherwise.
 */
int bst_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = bst_is_avl(tree->left);
	int right_height = bst_is_avl(tree->right);

	if (left_height == -1 || right_height == -1 ||
	    abs(left_height - right_height) > 1)
		return (-1);

	return (1 + (left_height > right_height ? left_height : right_height));
}
