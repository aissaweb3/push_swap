/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:02:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 11:07:48 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_parsed_data	parse_data(int ac, char **av)
{
	t_parsed_data	d;

	d.stack_a = init_stack(ac, av);
	if (d.stack_a == NULL)
		return (d);
	index_stack_a(d.stack_a);
	set_positions(d.stack_a);
	d.argc = d.stack_a->len;
	d.lis = malloc(d.argc * sizeof(int));
	d.lis_len = 0;
	if (d.lis == NULL)
		return (free_stack(&d.stack_a), d);
	d.stack_b = NULL;
	return (d);
}
