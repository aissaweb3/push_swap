/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/02 16:34:34 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_H
#  define STACK_H

#include <stdlib.h>
#include "push_swap_lang/language.h"

// cus the stack must be SCALABLE then we dont swap the data but the actual node 
typedef struct	s_mystack
{
	int					data;
	int					index;
	struct s_mystack	*next;
}				t_mystack;

t_mystack		*create_stack(int data);
t_mystack		*append_stack(t_mystack **head, t_mystack *tail, int new_data);

# endif