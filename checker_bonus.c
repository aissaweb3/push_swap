/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:33:16 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/16 13:16:16 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_result(t_parsed_data *my_data, t_mystack **a_b[2])
{
	set_positions(*a_b[0]);
	set_positions(*a_b[1]);
	if (stack_sorted(my_data, a_b) == OK)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&my_data->stack_a);
	free_stack(&my_data->stack_b);
	free(my_data->lis);
}

static void	read_and_apply(t_parsed_data *my_data, t_mystack **a_b[2])
{
	char	*instr;

	instr = get_next_line(0);
	while (instr)
	{
		apply_instr(my_data, instr, a_b);
		free(instr);
		instr = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_parsed_data	my_data;
	t_mystack		**a_b[2];

	validate(ac, av);
	my_data = parse_data(ac, av);
	if (my_data.stack_a == NULL)
		validation_error();
	a_b[0] = &my_data.stack_a;
	a_b[1] = &my_data.stack_b;
	read_and_apply(&my_data, a_b);
	check_result(&my_data, a_b);
	return (0);
}
