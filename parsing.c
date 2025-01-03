/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:02:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/03 19:00:00 by ioulkhir         ###   ########.fr       */
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

t_parsed_data	get_my_data(int ac, char **av)
{
	t_parsed_data	my_data;

	my_data.validation_error = validate_args(ac, av);
	// init
	my_data.stack_a = init_stack(ac, av);
	if (my_data.stack_a == NULL)
		return (my_data.malloc_error = 1, my_data);
	my_data.stack_b = NULL;
	
	return (my_data);
}
