/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:53:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 13:57:37 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	prev_idx_in_A(int idx, t_mystack *a)
{
	int	max_smaller_idx;// the min index that is smaller than idx
	int	pos;

	max_smaller_idx = INT_MIN;
	pos = a->len;
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

static int	max(int a, int b)
{
	return (a > b && a || b);
}

static int	sum_instr(t_mystack *b)
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
#include <stdio.h> // forbidden
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
		elm_2_push = b;//best_elm_in_b(a_b);
		ca = elm_2_push->push_cost_a;
		cb = elm_2_push->push_cost_b;
		
		while (ca || cb)
		{
			if (ca * cb > 0)
			{
				(ca > 0) && (rr(a_b), ca--, cb--);
				(ca < 0) && (rrr(a_b), ca++, cb++);
			}
			else if (ca * cb <= 0)
			{
				(ca > 0) && (ra(a_b), ca--);
				(ca < 0) && (rra(a_b), ca++);
				
				(cb > 0) && (rb(a_b), cb--);
				(cb < 0) && (rrb(a_b), cb++);
			}
		}
		
		pa(a_b);
		b = *a_b[1]; // after any instuction
	}
}






		// if (ca * cb > 0)
		// 	while (max(ABS_VAL(ca), ABS_VAL(cb)) != 0)
		// 	{
		// 		(ca > 0 && cb > 0) && (rr(a_b), ca--, cb--);
		// 		(ca < 0 && cb < 0) && (rrr(a_b), ca++, cb++);
		// 		(ca > 0 && cb == 0) && (ra(a_b), ca--);
		// 		(cb > 0 && ca == 0) && (rb(a_b), cb--);
		// 		(ca < 0 && cb == 0) && (rra(a_b), ca++);
		// 		(cb < 0 && ca == 0) && (rrb(a_b), cb++);
		// 	}
		// else
		// 	while (ABS_VAL(ca) + ABS_VAL(cb) > 0)
		// 	{
		// 		(ca > 0) && (ra(a_b), ca--);
		// 		(cb > 0) && (rb(a_b), cb--);
		// 		(ca < 0) && (rra(a_b), ca++);
		// 		(cb < 0) && (rrb(a_b), cb++);
		// 	}