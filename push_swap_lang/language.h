/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 10:50:30 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANGUAGE_H
# define LANGUAGE_H

# include "../push_swap.h"
# include "../stack/stack.h"

void	general_swap(t_mystack **head);
void	general_push(t_mystack **to, t_mystack **from);
void	general_rotate(t_mystack **head);
void	general_rev_rotate(t_mystack **head);

// lang
void	rr(t_mystack **a_b[2]);
void	rr_(t_mystack **a_b[2]);
void	rrr(t_mystack **a_b[2]);
void	rrr_(t_mystack **a_b[2]);
void	ss(t_mystack **a_b[2]);
void	ss_(t_mystack **a_b[2]);
void	rrr(t_mystack **a_b[2]);
void	rrr_(t_mystack **a_b[2]);
void	pa(t_mystack **a_b[2]);
void	pa_(t_mystack **a_b[2]);
void	ra(t_mystack **a_b[2]);
void	ra_(t_mystack **a_b[2]);
void	rra(t_mystack **a_b[2]);
void	rra_(t_mystack **a_b[2]);
void	sa(t_mystack **a_b[2]);
void	sa_(t_mystack **a_b[2]);
void	rra(t_mystack **a_b[2]);
void	rra_(t_mystack **a_b[2]);
void	pb(t_mystack **a_b[2]);
void	pb_(t_mystack **a_b[2]);
void	rb(t_mystack **a_b[2]);
void	rb_(t_mystack **a_b[2]);
void	rrb(t_mystack **a_b[2]);
void	rrb_(t_mystack **a_b[2]);
void	sb(t_mystack **a_b[2]);
void	sb_(t_mystack **a_b[2]);
void	rrb(t_mystack **a_b[2]);
void	rrb_(t_mystack **a_b[2]);

#endif
