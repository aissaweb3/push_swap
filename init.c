/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:17:43 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/06 16:18:10 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mystack	*init_stack(int ac, char **av)
{
	int 		i;
	t_mystack	*head;
	t_mystack	*tail;

	i = 1; // ignore the program name
	head = NULL;
	while (i < ac)
	{
		tail = append_stack(&head, tail, atoi(av[i++]));
		if (tail == NULL)
			return (free_stack(&head), NULL);
	}
	return (head);
}

