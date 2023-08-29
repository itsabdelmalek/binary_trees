#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	temp_root = new_root->left;
	new_root->left = tree;
	tree->right = temp_root;
	if (temp_root != NULL)
		temp_root->parent = tree;
	temp_root = tree->parent;
	tree->parent = new_root;
	new_root->parent = temp_root;
	if (temp_root != NULL)
	{
		if (temp_root->left == tree)
			temp_root->left = new_root;
		else
			temp_root->right = new_root;
	}

	return (new_root);
}
