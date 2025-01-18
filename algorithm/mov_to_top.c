/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:52:11 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/18 15:29:25 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static char	is_to_move(t_mystack *elm, int i, int data)
{
	return (elm->index == i
		|| (i == INVALID_IDX && elm->data == data));
}

void	mov_to_top(t_mystack **a_b[2],
	int index, int data)
{
	t_mystack	*head;
	t_mystack	*curr;
	t_mystack	*node;
	char		is_up;

	curr = *a_b[0];
	while (curr)
	{
		node = curr;
		if (is_to_move(node, index, data))
			break ;
		curr = curr->next;
	}
	set_positions(*a_b[0]);
	is_up = (node->position <= (node->len / 2 + (node->len % 2)));
	head = *a_b[0];
	while (head && is_to_move(head, index, data) == 0)
	{
		if (is_up)
			ra(a_b);
		else
			rra(a_b);
		head = *a_b[0];
	}
	set_positions(*a_b[0]);
}
