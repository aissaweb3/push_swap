/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:09:02 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/03 19:15:53 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../push_swap.h"
#include "../stack/stack.h"

/*
ALGO :
	finding the LIS :					iter
	PUSH none LIS						pb
	CALC best B element to PUSH			pa
	FIND the min						ra, rra
*/

void	find_LIS_and_push(t_parsed_data *my_data, t_mystack **a_b[2]);

#endif