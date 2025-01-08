/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:02:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 10:27:27 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// split



void	index_stack_a(t_mystack *a)
{
	t_mystack	*curr;
	t_mystack	*min_node;
	int			min_value;
	int			i;

	i = -1;
	while (1)
	{
		curr = a;
		min_node = NULL;
		min_value = INT_MAX;
		while (curr)
		{
			if (curr->index == NOT_SET && curr->data < min_value)
			{
				min_value = curr->data;
				min_node = curr;
			}
			curr = curr->next;
		}
		i++;
		if (min_node == NULL)
			break ;
		min_node->index = i;
	}
}

t_parsed_data	get_my_data(int ac, char **av)
{
	t_parsed_data	d;

	d.argc = ac - 1;
	d.validation_error = validate_args(ac, av);
	if (d.validation_error == ERR)
		return (d.malloc_error = 1, d);
	// init
	d.stack_a = init_stack(ac, av);
	if (d.stack_a == NULL)
		return (d.malloc_error = 1, d);
	index_stack_a(d.stack_a);
	set_positions(d.stack_a);
	// init LIS
	d.LIS = malloc(d.argc * sizeof(int));
	if (d.LIS == NULL)
		return (free_stack(&d.stack_a), d.malloc_error = 1, d);

	d.stack_b = NULL;
	
	return (d);
}
