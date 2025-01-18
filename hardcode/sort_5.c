/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:43:22 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/18 15:51:39 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hardcode.h"

static void	reset_idx(t_mystack *a)
{
	while (a)
	{
		a->index = NOT_SET;
		a = a->next;
	}
}

void	sort_5(t_mystack **a_b[2])
{
	mov_to_top(a_b, 0, 0);
	pb(a_b);
	mov_to_top(a_b, 1, 0);
	pb(a_b);
	reset_idx(*a_b[0]);
	index_stack_a(*a_b[0]);
	sort_3(a_b);
	pa(a_b);
	pa(a_b);
}
