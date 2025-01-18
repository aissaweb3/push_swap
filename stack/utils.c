/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:34:47 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/18 15:15:09 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lang/language.h"
#include "stack.h"

// returns null {if and only if} malloc fails
t_mystack	*create_stack(int data)
{
	t_mystack	*new_stack;

	new_stack = malloc(sizeof(t_mystack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->index = NOT_SET;
	new_stack->data = data;
	new_stack->len = 0;
	new_stack->ca = 0;
	new_stack->ca = 0;
	return (new_stack);
}

// returns null {if and only if} malloc fails
t_mystack	*push_elem(t_mystack **head, t_mystack *tail, int new_data)
{
	if (*head == NULL)
		return (*head = create_stack(new_data));
	tail->next = create_stack(new_data);
	return (tail->next);
}

t_mystack	*ft_lstlast(t_mystack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

void	free_stack(t_mystack **head)
{
	t_mystack	*curr;
	t_mystack	*next;

	curr = *head;
	while (curr)
	{
		next = curr->next;
		//if (next)
			//printf("[%d]", next->index - curr->index);
		free(curr);
		curr = next;
	}
	*head = NULL;
}

void	set_positions(t_mystack *a)
{
	t_mystack	*curr;
	int			position;

	curr = a;
	position = 1;
	while (curr)
	{
		curr->position = position++;
		curr = curr->next;
	}
	curr = a;
	while (curr)
	{
		curr->len = position - 1;
		curr = curr->next;
	}
}
