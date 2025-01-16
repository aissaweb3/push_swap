/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:47 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 13:48:28 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	stack_sorted(t_parsed_data *my_data, t_mystack **a_b[2])
{
	find_lis(my_data, a_b, my_data->lis, &my_data->lis_len);
	if (
		my_data->lis_len == my_data->argc
		&& (*a_b[0])->len == my_data->argc
		&& *a_b[1] == NULL
	)
		return (OK);
	return (KO);
}
