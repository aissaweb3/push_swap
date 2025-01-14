/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:55:13 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 10:47:47 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_mystack **s[2])
{
	pa_(s);
	write(1, "pa\n", 3);
}

void	pa_(t_mystack **s[2])
{
	t_mystack	**a;
	t_mystack	**b;

	a = s[0];
	b = s[1];
	general_push(b, a);
}
