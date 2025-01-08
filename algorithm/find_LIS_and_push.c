/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_LIS_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:53:05 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 17:54:47 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	push_non_LIS(t_parsed_data *my_data, t_mystack **a_b[2])
{
	char		non_LIS;
	int			j;
	t_mystack	*curr;

	curr = *a_b[0];
	while (curr)
	{
		non_LIS = 1;
		j = 0;
		while (j < my_data->LIS_len)
		{
			if (my_data->LIS[j] == curr->data)
				non_LIS = 0;
			j++;
		}
		if (non_LIS)
		{
			mov_to_top(my_data, a_b, INVALID_IDX, curr->data);
			pb(a_b);
			curr = *a_b[0];
		}
		else
			curr = curr->next;
	}
}

void	find_LIS_and_push(t_parsed_data *my_data, t_mystack **a_b[2])
{
	
	my_data->LIS = find_LIS(*a_b[0], &my_data->LIS_len);
	
	// -45 -4 -57 -41 18 62 72 87 136 154 176 192 199

	if (my_data->LIS_len == my_data->argc)
		return ;
	// if (my_data->LIS_len == 0)
		// rev();
	push_non_LIS(my_data, a_b);
}
