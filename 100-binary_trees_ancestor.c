#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL.
 * If no common ancestor was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancest_1, *ancest_2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	ancest_1 = first->parent, ancest_2 = second->parent;
	if (first == ancest_2 || !ancest_1 || (!ancest_1->parent && ancest_2))
		return (binary_trees_ancestor(first, ancest_2));
	else if (ancest_1 == second || !ancest_2 || (!ancest_2->parent && ancest_1))
		return (binary_trees_ancestor(ancest_1, second));
	return (binary_trees_ancestor(ancest_1, ancest_2));
}
