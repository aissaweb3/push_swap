/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:48:45 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 09:44:43 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_dup(t_mystack *head, t_arg *arg)
{
	while (head)
	{
		if (head->data == arg->value)
			arg->is_uniq = NOT_UNIQ;
		head = head->next;
	}
}
