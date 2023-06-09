/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 03:46:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/04/11 15:11:24 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*create_node(void *data)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (new_node == NULL)
		return (NULL);
	new_node->previous = NULL;
	new_node->next = NULL;
	new_node->data = data;
	return (new_node);
}

void	add_node(t_dlist **head, t_dlist *new_node)
{
	t_dlist	*current;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->previous = current;
	}
}

void	delete_node(t_dlist **head, t_dlist *node_to_delete)
{
	if (*head == node_to_delete)
		*head = node_to_delete->next;
	if (node_to_delete->previous != NULL)
		node_to_delete->previous->next = node_to_delete->next;
	if (node_to_delete->next != NULL)
		node_to_delete->next->previous = node_to_delete->previous;
	free (node_to_delete);
}

void	free_linked_list(t_dlist **head)
{
	t_dlist	*current;
	t_dlist	*next;

	current = *head;
	next = NULL;
	while (current != NULL)
	{
		free (current->data);
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
