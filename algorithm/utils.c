/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:51:18 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/17 13:04:35 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	prev_idx_in_a(int idx, t_mystack *a)
{
	int	max_smaller_idx;
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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	sum_instr(t_mystack *b)
{
	int	ca;
	int	cb;
	int	result;

	ca = b->ca;
	cb = b->cb;
	result = 0;
	if (ca * cb > 0)
		result = max(abs_val(ca), abs_val(cb));
	else if (ca * cb <= 0)
		result = abs_val(ca) + abs_val(cb);
	return (result);
}
