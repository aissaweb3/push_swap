/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/03 11:52:55 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANGUAGE_H
# define LANGUAGE_H

# include "../push_swap.h"
#include "../stack/stack.h"

void	general_swap(t_mystack **head);
void	general_push(t_mystack **to, t_mystack **from);
void	general_rotate(t_mystack **head);
void	general_rev_rotate(t_mystack **head);

// lang
void	rr(t_mystack **a, t_mystack **b);
void	rrr(t_mystack **a, t_mystack **b);
void	ss(t_mystack **a, t_mystack **b);
void	pa(t_mystack **a, t_mystack **b);
void	ra(t_mystack **a);
void	ra_(t_mystack **a);
void	rra(t_mystack **a);
void	rra_(t_mystack **a);
void	sa(t_mystack **a);
void	sa_(t_mystack **a);
void	pb(t_mystack **a, t_mystack **b);
void	rb(t_mystack **b);
void	rb_(t_mystack **b);
void	rrb(t_mystack **b);
void	rrb_(t_mystack **b);
void	sb(t_mystack **b);
void	sb_(t_mystack **b);

#endif
