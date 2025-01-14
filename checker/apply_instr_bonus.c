/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:12:41 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 10:52:19 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	custom_hash(char *input_str)
{
	char	*valid_inputs[NUM_VALID_INPUTS];
	int		i;

	i = 0;
	valid_inputs[0] = "pa";
	valid_inputs[1] = "ra";
	valid_inputs[2] = "rra";
	valid_inputs[3] = "sa";
	valid_inputs[4] = "rrr";
	valid_inputs[5] = "rrb";
	valid_inputs[6] = "rr";
	valid_inputs[7] = "ss";
	valid_inputs[8] = "pb";
	valid_inputs[9] = "rb";
	valid_inputs[10] = "sb";
	while (i < NUM_VALID_INPUTS)
	{
		if (ft_strncmp(input_str, valid_inputs[i],
				ft_strlen(valid_inputs[i])) == 0)
			return (i);
		i++;
	}
	return (NUM_VALID_INPUTS);
}

void	apply_instr(t_parsed_data *my_data, char *instr, t_mystack **a_b[2])
{
	void	(*operations[11])(t_mystack **s[2]);
	int		op_index;

	operations[0] = pa_;
	operations[1] = ra_;
	operations[2] = rra_;
	operations[3] = sa_;
	operations[4] = rrr_;
	operations[5] = rrb_;
	operations[6] = rr_;
	operations[7] = ss_;
	operations[8] = pb_;
	operations[9] = rb_;
	operations[10] = sb_;
	op_index = custom_hash(instr);
	if (op_index == NUM_VALID_INPUTS)
	{
		free_stack(&my_data->stack_a);
		free_stack(&my_data->stack_b);
		free(my_data->lis);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	(operations[op_index])(a_b);
}
