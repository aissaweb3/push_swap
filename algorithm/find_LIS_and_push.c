/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_LIS_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:53:05 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 14:09:53 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	find_LIS(t_parsed_data *my_data, t_mystack **a_b[2], int *LIS, int *LIS_len)
{
	t_mystack	*curr;
	t_mystack	*a;
	int			max_idx;
	int			i;

	a = *a_b[0];
	curr = (a)->next;
	max_idx = my_data->argc - 1;
	i = 0;
	*LIS_len = 1;
	LIS[i] = a->data;
	while (curr)
	{
		if (curr->index <= max_idx && curr->data > LIS[i])
		{
			(*LIS_len)++;
			if (i > max_idx / 2)
				max_idx += curr->index;
			LIS[++i] = curr->data;
		}
		curr = curr->next;
	}
}

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
	find_LIS(my_data, a_b, my_data->LIS, &my_data->LIS_len);
	
	// -45 -4 -57 -41 18 62 72 87 136 154 176 192 199

	if (my_data->LIS_len == my_data->argc)
		return ;
	// if (my_data->LIS_len == 0)
		// rev();
	push_non_LIS(my_data, a_b);
}
