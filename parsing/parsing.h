/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:09:02 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 11:07:57 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../push_swap.h"
# include "../parsed_data.h"
# include "../stack/stack.h"
# include <limits.h>

typedef struct s_arg
{
	char		is_valid;
	char		is_uniq;
	long		value;
}				t_arg;

void			validate(int ac, char **av);
t_arg			validate_arg(char *arg);
void			validation_error(void);
void			check_dup(t_mystack *head, t_arg *arg);

t_parsed_data	parse_data(int ac, char **av);
t_mystack		*init_stack(int ac, char **av);
void			index_stack_a(t_mystack *a);

# define UNIQ 15
# define NOT_UNIQ -15
# define SET 15

#endif