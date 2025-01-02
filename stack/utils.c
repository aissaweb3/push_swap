/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:34:47 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/02 16:35:27 by ioulkhir         ###   ########.fr       */
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
	new_stack->data = data;
	return (new_stack);
}

// returns null {if and only if} malloc fails
t_mystack	*append_stack(t_mystack **head, t_mystack *tail, int new_data)
{
	t_mystack	*new_stack;

	if (*head == NULL)
		return (*head = create_stack(new_data));
	tail->next = create_stack(new_data);
	return (tail->next);
}
