/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra-rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:57:40 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 10:49:23 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_mystack **s[2])
{
	ra_(s);
	write(1, "ra\n", 3);
}

void	ra_(t_mystack **s[2])
{
	t_mystack	**a;

	a = s[0];
	general_rotate(a);
}

void	rra(t_mystack **s[2])
{
	rra_(s);
	write(1, "rra\n", 4);
}

void	rra_(t_mystack **s[2])
{
	t_mystack	**a;

	a = s[0];
	general_rev_rotate(a);
}
