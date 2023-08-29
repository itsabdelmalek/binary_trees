#include "binary_trees.h"

/**
 * create_node - Creates a new node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * push_queue - Runs a function on a given binary tree node and
 *             pushes its children into a queue.
 * @node: The binary tree node to process and push.
 * @queue: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on the node's value.
 */
void push_queue(binary_tree_t *node, levelorder_queue_t **queue,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(*queue);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(*queue);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop_head - Pops the head of a queue.
 * @head: A double pointer to the head of the queue.
 */
void pop_head(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *queue = NULL, *tail = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = tail = create_node((binary_tree_t *)tree);
	if (queue == NULL)
		return;

	while (queue != NULL)
	{
		push_queue(queue->node, &queue, &tail, func);
		pop_head(&queue);
	}
}
