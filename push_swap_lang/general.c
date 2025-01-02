/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:46:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/02 16:27:46 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	general_swap(t_mystack *stack)
{
	t_mystack	*elm1;
	t_mystack	*elm2;
	t_mystack	*tmp;

	elm1 = stack;
	if (stack == NULL)
		return ;
	elm2 = stack->next;
	if (stack->next == NULL)
		return ;
	tmp = elm2->next;
	elm2->next = elm1;
	elm1->next = tmp;
}
