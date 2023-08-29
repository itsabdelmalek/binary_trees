#include "binary_trees.h"

/**
 * min_value_node_bst - Finds the node with the minimum value in a BST.
 * @node: A pointer to the node to start the search from.
 *
 * Return: A pointer to the node with the minimum value.
 */
bst_t *min_value_node_bst(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * remove_node_bst - Removes a node from a BST while maintaining properties.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to be removed.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *remove_node_bst(bst_t *root, bst_t *node)
{
	if (node == NULL)
		return (root);

	if (node->left == NULL)
	{
		bst_t *right_child = node->right;

		free(node);
		return (right_child);
	}
	if (node->right == NULL)
	{
		bst_t *left_child = node->left;

		free(node);
		return (left_child);
	}

	bst_t *successor = min_value_node_bst(node->right);

	node->n = successor->n;
	node->right = remove_node_bst(root, successor);

	return (root);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		root = remove_node_bst(root, root);
	}
	return (root);
}
