/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:16:09 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 17:45:12 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	restore(int count, t_mystack **a_b[2])
{
	while (count > 0)
		1 && (rra_(a_b), count--);
	while (count < 0)
		1 && (ra_(a_b), count++);
}

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2])
{
	int	count;

	count = mov_to_top_silent(my_data, a_b, 0, 0);
	restore(count, a_b);
	find_LIS_and_push(my_data, a_b);  // O(n) = n      we still have 6n
	calc_rotate_push(my_data, a_b);  // this one takes a lot     (> 5n)
	mov_to_top(my_data, a_b, 0, 0); // O(n) = n
}
