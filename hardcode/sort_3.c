/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:43:22 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/18 13:53:22 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hardcode.h"

void	sort_3(t_mystack **a_b[2])
{
	t_mystack	*a;

	a = *a_b[0];
	set_positions(a);
	while (a->index == 2 || a->next->index == 2)
		1 && (ra(a_b), a = *a_b[0]);
	if (a->index == 1)
		sa(a_b);
}