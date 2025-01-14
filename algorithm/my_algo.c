/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:16:09 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 13:44:25 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2])
{
	mov_to_top(my_data, a_b, 0, 0);
	find_lis_and_push(my_data, a_b);
	calc_rotate_push(a_b);
	mov_to_top(my_data, a_b, 0, 0);
}
