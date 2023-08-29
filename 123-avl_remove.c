#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: The value to remove from the AVL tree.
 *
 * Return: Pointer to the new root node after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			avl_t *temp = root->left ? root->left : root->right;

			free(root);
			return (temp);
		}

		avl_t *temp = avl_find_successor(root->right);

		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	return (avl_rebalance(root));
}

/**
 * avl_rebalance - Rebalances an AVL tree.
 * @node: The root node of the AVL tree to be rebalanced.
 *
 * Return: The new root node after rebalancing.
 */
avl_t *avl_rebalance(avl_t *node)
{
	int balance = avl_balance(node);

	if (balance > 1 && avl_balance(node->left) >= 0)
		return (avl_rotate_right(node));

	if (balance < -1 && avl_balance(node->right) <= 0)
		return (avl_rotate_left(node));

	if (balance > 1 && avl_balance(node->left) < 0)
	{
		node->left = avl_rotate_left(node->left);
		return (avl_rotate_right(node));
	}

	if (balance < -1 && avl_balance(node->right) > 0)
	{
		node->right = avl_rotate_right(node->right);
		return (avl_rotate_left(node));
	}

	return (node);
}
