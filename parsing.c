/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:02:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/06 14:09:45 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	validate_args(int ac, char **av)
{
	// validate input data
	return (0);
}

t_mystack	*init_stack(int ac, char **av)
{
	int 		i;
	t_mystack	*head;
	t_mystack	*tail;

	i = 1; // ignore the program name
	head = NULL;
	while (i < ac)
		tail = append_stack(&head, tail, atoi(av[i++]));
	return (head);
}

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
	t_parsed_data	my_data;

	my_data.validation_error = validate_args(ac, av);
	// init
	my_data.stack_a = init_stack(ac, av);
	
	index_stack_a(my_data.stack_a);
	if (my_data.stack_a == NULL)
		return (my_data.malloc_error = 1, my_data);
	my_data.stack_b = NULL;
	
	return (my_data);
}
