#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: None.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		exit(1);

	int front = 0, rear = 0;
	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];
		func(current->n);

		if (current->left)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (rear + 1));
			if (queue == NULL)
			{
				free(queue);
				exit(1);
			}
			queue[rear++] = current->left;
		}
		if (current->right)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (rear + 1));
			if (queue == NULL)
			{
				free(queue);
				exit(1);
			}
			queue[rear++] = current->right;
		}
	}
	free(queue);
}
