/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb-rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:57:40 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/03 11:37:38 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_mystack **b)
{
	rb_(b);
	write(1, "rb\n", 3);
}

void	rb_(t_mystack **b)
{
	general_rotate(b);
}

void	rrb(t_mystack **b)
{
	rrb_(b);
}

void	rrb_(t_mystack **b)
{
	write(1, "rrb\n", 4);
}
