/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/07 10:43:17 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "push_swap_lang/language.h"
# include "stack/stack.h"
# include <limits.h>

typedef struct	s_parsed_data
{
	int				argc;
	char			malloc_error;
	char			validation_error;
	t_mystack		*stack_a;
	t_mystack		*stack_b;
	int				*LIS;
	int				LIS_len;
}				t_parsed_data;

# include "algorithm/algorithm.h"

#define NOT_SET -314
#define NO_ERR 1
#define ERR 0
	
	
t_parsed_data	get_my_data(int ac, char **av);
t_mystack		*init_stack(int ac, char **av);
char			validate_args(int ac, char **av);

#endif