/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:16:09 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/07 14:53:22 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

char	is_to_move(t_mystack *elm, int i, int data)
{
	return (elm->index == i
			|| (i == INVALID_IDX && elm->data == data));
}

void	mov_to_top(t_parsed_data *my_data, t_mystack **a_b[2], int index, int data)
{
	t_mystack	*head;
	t_mystack	*curr;
	t_mystack	*node;
	char		is_up;

	curr = *a_b[0];
	// choose plan
	while (curr)
	{
		node = curr;
		if (is_to_move(node, index, data))
			break ;
		curr = curr->next;
	}
	is_up = (node->position <= my_data->argc / 2);
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

#include <stdio.h>
// forbidden

int	*find_LIS(t_parsed_data *my_data, t_mystack **a_b[2], int *LIS, int *LIS_len)
{
	t_mystack	*curr;
	t_mystack	*a;
	int			max_idx;
	int			i;

	a = *a_b[0];
	curr = (a)->next;
	max_idx = my_data->argc - 1;
	i = 0;
	*LIS_len = 1;
	LIS[i] = a->data;
	while (curr)
	{
		if (curr->index <= max_idx / 1.1 && curr->data > LIS[i])
		{
			(*LIS_len)++;
			if (i > max_idx / 2)
				max_idx += curr->index;
			LIS[++i] = curr->data;
		}
		curr = curr->next;
	}
	return (LIS);
}

void	calc_push_cost_b(t_mystack **a_b[2])
{
	t_mystack	*curr_a;
	t_mystack	*curr_b;
	int			pos;
	
	curr_a = *a_b[0];
	curr_b = *a_b[1];
	set_positions(curr_b);
	set_positions(curr_a);
	while (curr_b)
	{
		pos = curr_b->position;
		// eq: cost = len(A) - prev_pos_in_A(pos) || - prev_pos_in_A(pos)
		// eq: cost = (pos - 1) || - (pos - 1) ----> val = result % len
		curr_b->push_cost_a = 0;
		curr_b->push_cost_b = (pos > curr_b->len / 2) ? 1 : -1 * (pos - 1);
		curr_b = curr_b->next;
	}
	
}

void	push_non_LIS(t_parsed_data *my_data, t_mystack **a_b[2])
{
	int			*LIS;
	char		non_LIS;
	int			j;
	t_mystack	*curr;

	curr = *a_b[0];
	while (curr)
	{
		non_LIS = 1;
		j = 0;
		while (j < my_data->LIS_len)
		{
			if (LIS[j] == curr->data)
				non_LIS = 0;
			j++;
		}
		if (non_LIS)
		{
			mov_to_top(my_data, a_b, INVALID_IDX, curr->data);
			pb(a_b);
			curr = *a_b[0];
		}
		else
			curr = curr->next;
	}
}
void	find_LIS_and_push(t_parsed_data *my_data, t_mystack **a_b[2])
{
	int			*LIS;

	mov_to_top(my_data, a_b, 0, 0); // anything for the value
	LIS = find_LIS(my_data, a_b, my_data->LIS, &my_data->LIS_len);
	
	if (my_data->LIS_len == my_data->argc)
		return ;
	// if (my_data->LIS_len == 0)
		// rev();
	push_non_LIS(my_data, a_b);

	calc_push_cost_b(a_b);
}
