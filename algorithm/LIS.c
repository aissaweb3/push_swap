/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:16:09 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 10:49:37 by ioulkhir         ###   ########.fr       */
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

void	find_LIS(t_parsed_data *my_data, t_mystack **a_b[2], int *LIS, int *LIS_len)
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
}

// returns the postion 
int	prev_idx_in_A(int idx, t_mystack *a)
{
	int	max_smaller_idx;// the min index that is smaller than idx
	int	pos;

	max_smaller_idx = INT_MIN;
	while (a)
	{
		if (a->index < idx && a->index > max_smaller_idx)
		{
			max_smaller_idx = a->index;
			pos = a->position;
		}
		a = a->next;
	}
	return (pos);
}

void	calc_push_cost_b(t_mystack **a_b[2])
{
	t_mystack	*a;
	t_mystack	*b;
	int			pos;
	char		is_up;
	
	a = *a_b[0];
	b = *a_b[1];
	set_positions(b);
	set_positions(a);
	while (b)
	{
		pos = b->position - 1;
		// eq: cost = len(A) - prev_pos_in_A(pos) || - prev_pos_in_A(pos)
		// eq: cost = (pos - 1) || - (pos - 1) ----> val = result % len
		
		// set cost in b
		is_up = pos <= (b->len + 1) / 2;
		b->push_cost_b = -(b->len - pos);
		is_up == 1 && (b->push_cost_b = pos);
		
		// set cost in a
		pos = prev_idx_in_A(b->index, a);
		
		is_up = pos < (a->len + 1) / 2;
		b->push_cost_a = pos - a->len;
		is_up == 1 && (b->push_cost_a = pos);
		
		b = b->next;
	}
	
}

void	push_non_LIS(t_parsed_data *my_data, t_mystack **a_b[2])
{
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
			if (my_data->LIS[j] == curr->data)
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

int	max(int a, int b)
{
	return (a > b && a || b);
}

int	sum_instr(t_mystack *b)
{
	int c1;
	int c2;
	int	result;
	
	c1 = b->push_cost_a;
	c2 = b->push_cost_b;
	if (c1 * c2 > 0)
		return (max(c1, c2)); // ra + rb = rr
	else if (c1 * c2 <= 0)
		return (ABS_VAL(c1) + ABS_VAL(c2));
	return (0);
}

t_mystack	*best_elm_in_b(t_mystack **a_b[2])
{
	t_mystack	*elm_2_push;
	t_mystack	*b;

	b = *a_b[1];
	elm_2_push = b;
	while (b)
	{
		// sum_instructions ---> sum_instr
		if (sum_instr(b) < sum_instr(elm_2_push))
			elm_2_push = b;
		b = b->next;
	}
	return (elm_2_push);
}

void	calc_rotate_push(t_parsed_data *my_data, t_mystack **a_b[2])
{
	int 		ca;
	int 		cb;
	t_mystack	*elm_2_push;
	t_mystack	*b;

	b = *a_b[1];
	while (b != NULL)
	{
	
		// CRP:
		//		CALC
		//		ROTATE
		// 		PUSH
	
		calc_push_cost_b(a_b); // am proud of the calculation hhhh
		elm_2_push = best_elm_in_b(a_b);
		ca = elm_2_push->push_cost_a;
		cb = elm_2_push->push_cost_b;
		
		
		if (ca * cb > 0)
			while (max(ABS_VAL(ca), ABS_VAL(cb)) != 0)
			{
				(ca > 0 && cb > 0) && (rr(a_b), ca--, cb--);
				(ca < 0 && cb < 0) && (rrr(a_b), ca++, cb++);
				(ca > 0 && cb == 0) && (ra(a_b), ca--);
				(cb > 0 && ca == 0) && (rb(a_b), cb--);
				(ca < 0 && cb == 0) && (rra(a_b), ca++);
				(cb < 0 && ca == 0) && (rrb(a_b), cb++);
			}
		else
			while (ABS_VAL(ca) + ABS_VAL(cb) > 0)
			{
				(ca > 0) && (ra(a_b), ca--);
				(cb > 0) && (rb(a_b), cb--);
				(ca < 0) && (rra(a_b), ca++);
				(cb < 0) && (rrb(a_b), cb++);
			}
		pa(a_b);
		b = *a_b[1]; // after any instuction
	}
}

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2])
{
	mov_to_top(my_data, a_b, 0, 0); // anything for the value
	find_LIS_and_push(my_data, a_b);
	calc_rotate_push(my_data, a_b);
	mov_to_top(my_data, a_b, 0, 0); // anything for the value
}

void	find_LIS_and_push(t_parsed_data *my_data, t_mystack **a_b[2])
{
	find_LIS(my_data, a_b, my_data->LIS, &my_data->LIS_len);
	
	// -45 -4 -57 -41 18 62 72 87 136 154 176 192 199

	if (my_data->LIS_len == my_data->argc)
		return ;
	// if (my_data->LIS_len == 0)
		// rev();
	push_non_LIS(my_data, a_b);
}
