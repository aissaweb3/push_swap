/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:09:02 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 16:58:41 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../push_swap.h"
# include "../stack/stack.h"

# define INVALID_IDX -314

/*
ALGO :
	finding the LIS :					iter
	PUSH none LIS						pb
	CALC best B element to PUSH			pa
	FIND the min						ra, rra
*/

# define ABS_VAL(x) ((x > 0) - 0.5) * 2 * (x)

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2]);

void	mov_to_top(t_parsed_data *my_data, t_mystack **a_b[2], int index, int data);
int		mov_to_top_silent(t_parsed_data *my_data, t_mystack **a_b[2], int index, int data);
void	find_LIS_and_push(t_parsed_data *my_data, t_mystack **a_b[2]);
void	calc_rotate_push(t_parsed_data *my_data, t_mystack **a_b[2]);
int* 	find_LIS(t_mystack *stack, int *length);

#endif