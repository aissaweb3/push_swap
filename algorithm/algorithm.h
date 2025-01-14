/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:09:02 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 09:34:05 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../push_swap.h"
# include "../stack/stack.h"

# define INVALID_IDX -314

void	my_algo(t_parsed_data *my_data, t_mystack **a_b[2]);
void	mov_to_top(t_parsed_data *my_data, t_mystack **a_b[2],
			int index, int data);
void	find_lis_and_push(t_parsed_data *my_data, t_mystack **a_b[2]);
void	find_lis(t_parsed_data *my_data, t_mystack **a_b[2],
			int *lis, int *lis_len);
void	calc_rotate_push(t_parsed_data *my_data, t_mystack **a_b[2]);

// utils

int		prev_idx_in_a(int idx, t_mystack *a);
int		max(int a, int b);
int		abs_val(int x);
int		sum_instr(t_mystack *b);

#endif