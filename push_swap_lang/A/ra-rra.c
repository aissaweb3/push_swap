/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra-rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:57:40 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/03 12:53:09 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_mystack **a)
{
	ra_(a);
	write(1, "ra\n", 3);
}

void	ra_(t_mystack **a)
{
	general_rotate(a);
}

void	rra(t_mystack **a)
{
	rra_(a);
}

void	rra_(t_mystack **a)
{
	general_rev_rotate(a);
	write(1, "rra\n", 4);
}
