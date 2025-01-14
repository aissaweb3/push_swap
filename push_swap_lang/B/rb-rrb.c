/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb-rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:57:40 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/11 17:58:08 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rb(t_mystack **s[2])
{
	rb_(s);
	write(1, "rb\n", 3);
}

void	rb_(t_mystack **s[2])
{
	t_mystack	**b;

	b = s[1];
	general_rotate(b);
}

void	rrb(t_mystack **s[2])
{
	rrb_(s);
	write(1, "rrb\n", 4);
}

void	rrb_(t_mystack **s[2])
{
	t_mystack	**b;

	b = s[1];
	general_rev_rotate(b);
}
