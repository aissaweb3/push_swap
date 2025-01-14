/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:25:54 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 10:27:39 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSED_DATA_H
# define PARSED_DATA_H

# include "stack/stack.h"

typedef struct s_parsed_data
{
	int				argc;
	t_mystack		*stack_a;
	t_mystack		*stack_b;
	int				*lis;
	int				lis_len;
}				t_parsed_data;

#endif