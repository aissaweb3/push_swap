/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:33:16 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/16 14:52:54 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_parsed_data	my_data;
	t_mystack		**a_b[2];

	if (ac == 1)
		exit(EXIT_FAILURE);
	my_data = parse_data(ac, av);
	if (my_data.stack_a == NULL)
		validation_error();
	a_b[0] = &my_data.stack_a;
	a_b[1] = &my_data.stack_b;
	my_algo(&my_data, a_b);
	free_stack(&my_data.stack_a);
	free(my_data.lis);
	return (0);
}
