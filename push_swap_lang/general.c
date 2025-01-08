/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:46:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/07 13:29:53 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	general_swap(t_mystack **head)
{
	t_mystack	*elm1;
	t_mystack	*elm2;
	t_mystack	*tmp;

	elm1 = *head;
	if (*head == NULL)
		return ;
	elm2 = (*head)->next;
	if ((*head)->next == NULL)
		return ;
	tmp = elm2->next;
	elm2->next = elm1;
	elm1->next = tmp;
	*head = elm2;
}

void	general_push(t_mystack **from, t_mystack **to)
{
	t_mystack	*elem_to_push;

	if (*from == NULL)
		return ;
	elem_to_push = *from;
	*from = (*from)->next;
	elem_to_push->next = *to;
	*to = elem_to_push;
}

void	general_rotate(t_mystack **head)
{
	t_mystack	*first_elem;
	t_mystack	*last_elem;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first_elem = *head;
	last_elem = ft_lstlast(*head);
	*head = first_elem->next;
	first_elem->next = NULL;
	last_elem->next = first_elem;
}

void	general_rev_rotate(t_mystack **head)
{
	t_mystack	*second_last_elem;
	t_mystack	*last_elem;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	second_last_elem = *head;
	while (second_last_elem->next->next != NULL)
		second_last_elem = second_last_elem->next;
	last_elem = second_last_elem->next;
	second_last_elem->next = NULL;
	last_elem->next = *head;
	*head = last_elem;
}
