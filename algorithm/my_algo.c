/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:16:09 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 13:57:13 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2])
{
	mov_to_top(my_data, a_b, 0, 0); // anything for the value
	find_LIS_and_push(my_data, a_b);
	calc_rotate_push(my_data, a_b);
	mov_to_top(my_data, a_b, 0, 0); // anything for the value
}
