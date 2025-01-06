/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/06 14:10:09 by ioulkhir         ###   ########.fr       */
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
	char		malloc_error;
	char		validation_error;
	t_mystack	*stack_a;
	t_mystack	*stack_b;
}				t_parsed_data;

#define NOT_SET -314

t_parsed_data	get_my_data(int ac, char **av);

#endif