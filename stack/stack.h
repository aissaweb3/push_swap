/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 09:34:41 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "struct.h"
# include "../push_swap_lang/language.h"

t_mystack		*create_stack(int data);
t_mystack		*push_elem(t_mystack **head, t_mystack *tail, int new_data);
t_mystack		*ft_lstlast(t_mystack *head);
void			free_stack(t_mystack **stack);
void			set_positions(t_mystack *a);

#endif