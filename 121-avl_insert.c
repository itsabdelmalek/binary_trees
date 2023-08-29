#include "binary_trees.h"


/**
 * tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l_h = 0, r_h = 0;

		l_h = tree->left ? 1 + tree_height(tree->left) : 0;
		r_h = tree->right ? 1 + tree_height(tree->right) : 0;
		return ((l_h > r_h) ? l_h : r_h);
	}
	return (0);
}

/**
 * tree_balance - Measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor of the binary tree, or 0 if tree is NULL.
 */
int tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (tree_height(tree->left) - tree_height(tree->right));

	return (0);
}

/**
 * avl_insert_rec - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_rec(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int tmp;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_rec(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_rec(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	tmp = tree_balance(*tree);
	if (tmp > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (tmp < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (tmp > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (tmp < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_rec(tree, *tree, &new, value);
	return (new);
}
