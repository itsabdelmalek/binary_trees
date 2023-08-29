#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: double pointer to the root node of the AVL tree for insert the value
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	*tree = insert_avl_recursive(*tree, value);
	if (*tree == NULL)
		return (NULL);

	return (bst_balance(*tree));
}

/**
 * insert_avl_recursive - Recursively inserts a value in an AVL Tree.
 * @tree: A pointer to the root node of the AVL tree for inserting the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the root of the AVL tree after insertion.
 */
avl_t *insert_avl_recursive(avl_t *tree, int value)
{
	if (tree == NULL)
		return (binary_tree_node(NULL, value));

	if (value < tree->n)
		tree->left = insert_avl_recursive(tree->left, value);
	else if (value > tree->n)
		tree->right = insert_avl_recursive(tree->right, value);

	return (tree);
}

/**
 * bst_balance - Balances an AVL tree.
 * @tree: A pointer to the root node of the AVL tree to balance.
 *
 * Return: A pointer to the root of the balanced AVL tree.
 */
avl_t *bst_balance(avl_t *tree)
{
	int balance;

	if (tree == NULL)
		return (NULL);

	balance = binary_tree_balance(tree);

	if (balance > 1 && binary_tree_balance(tree->left) >= 0)
		return (binary_tree_rotate_right(tree));

	if (balance > 1 && binary_tree_balance(tree->left) < 0)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}

	if (balance < -1 && binary_tree_balance(tree->right) <= 0)
		return (binary_tree_rotate_left(tree));

	if (balance < -1 && binary_tree_balance(tree->right) > 0)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}
