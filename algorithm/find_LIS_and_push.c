/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_LIS_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:53:05 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/17 13:38:04 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	find_lis(t_parsed_data *my_data, t_mystack **a_b[2],
	int *lis, int *lis_len)
{
	t_mystack	*curr;
	t_mystack	*a;
	int			max_idx;
	int			i;

	a = *a_b[0];
	curr = (a)->next;
	max_idx = my_data->argc - 1;
	i = 0;
	*lis_len = 1;
	lis[i] = a->data;
	while (curr)
	{
		if (curr->index <= max_idx && curr->data > lis[i])
		{
			(*lis_len)++;
			if (i > max_idx / 2)
				max_idx += curr->index;
			lis[++i] = curr->data;
		}
		curr = curr->next;
	}
}

void	push_non_lis(t_parsed_data *my_data, t_mystack **a_b[2])
{
	char		non_lis;
	int			j;
	t_mystack	*curr;

	curr = *a_b[0];
	while (curr)
	{
		non_lis = 1;
		j = 0;
		while (j < my_data->lis_len)
		{
			if (my_data->lis[j] == curr->data)
				non_lis = 0;
			j++;
		}
		if (non_lis)
		{
			mov_to_top(my_data, a_b, INVALID_IDX, curr->data);
			pb(a_b);
			curr = *a_b[0];
		}
		else
			curr = curr->next;
	}
}

void	find_lis_and_push(t_parsed_data *my_data, t_mystack **a_b[2])
{
	t_mystack	*a;
	int			count;

	a = *a_b[0];
	count = 0;
	while (a->index != 0)
		1 && (rra_(a_b), count++, a = *a_b[0]);
	find_lis(my_data, a_b, my_data->lis, &my_data->lis_len);
	if (my_data->lis_len == my_data->argc)
		return ;
	while(count)
		1 && (ra_(a_b), count--);
	push_non_lis(my_data, a_b);
}
