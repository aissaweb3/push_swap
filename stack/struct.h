/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:34:44 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/17 13:04:35 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mystack
{
	int					data;
	int					index;
	int					position;
	int					len;
	int					ca;
	int					cb;
	struct s_mystack	*next;
}				t_mystack;

#endif