/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:53:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 11:13:05 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

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
		is_up = pos <= (b->len + 1) / 2;
		b->push_cost_b = pos - b->len;
		is_up == 1 && (b->push_cost_b = pos);
		pos = prev_idx_in_a(b->index, a);
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
		if (sum_instr(b) < sum_instr(elm_2_push))
			elm_2_push = b;
		b = b->next;
	}
	return (elm_2_push);
}

static void	cheap_rotate_stacks(t_mystack **a_b[2], int ca, int cb)
{
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
}

void	calc_rotate_push(t_parsed_data *my_data, t_mystack **a_b[2])
{
	int			ca;
	int			cb;
	t_mystack	*elm_2_push;
	t_mystack	*b;

	b = *a_b[1];
	while (b != NULL)
	{
		calc_push_cost_b(a_b);
		elm_2_push = best_elm_in_b(a_b);
		ca = elm_2_push->push_cost_a;
		cb = elm_2_push->push_cost_b;
		cheap_rotate_stacks(a_b, ca, cb);
		pa(a_b);
		b = *a_b[1];
	}
}
