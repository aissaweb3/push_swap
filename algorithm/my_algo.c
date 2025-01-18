/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:16:09 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/18 13:24:44 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2])
{
	find_lis_and_push(my_data, a_b);	// 500
	calc_rotate_push(a_b);				// 5318
	mov_to_top(my_data, a_b, 0, 0);		// 239
}
