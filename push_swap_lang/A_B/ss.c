/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:23:30 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 10:47:21 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ss(t_mystack **s[2])
{
	ss_(s);
	write(1, "ss\n", 3);
}

void	ss_(t_mystack **s[2])
{
	sa_(s);
	sb_(s);
}
