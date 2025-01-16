/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 13:48:40 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../push_swap.h"
# include "../gnl/get_next_line.h"

char	stack_sorted(t_parsed_data *my_data, t_mystack **a_b[2]);
void	apply_instr(t_parsed_data *my_data, char *instr, t_mystack **a_b[2]);
ssize_t	read_line(char *buffer);

# define NUM_VALID_INPUTS 11
# define OK 13
# define KO -13

#endif
