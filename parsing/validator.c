/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:23:51 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/13 10:59:10 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	validation_error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	validate(int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (ac == 2 && av[1][0] == '\0')
		validation_error();
}

t_arg	validate_arg(char *arg)
{
	t_arg	n;
	char	sign;
	int		i;

	i = 0;
	sign = 1;
	n.value = 0;
	n.is_uniq = UNIQ;
	if (arg[0] == '\0')
		return (n.is_valid = 0, n);
	while (arg[i] && arg[i] == ' ')
		i++;
	(arg[i] == '+') && (sign = SET, i++);
	(arg[i] == '-' && sign != SET) && (sign = -1, i++);
	while (arg[i] && ft_isdigit(arg[i]) && n.value < INT_MAX)
		1 && (n.value = n.value * 10 + (arg[i++] - '0'));
	n.value *= ((double)((sign > 0) - 0.5) *2);
	n.is_valid = (
			arg[i] == '\0'
			&& ft_isdigit(arg[i - 1])
			&& n.value >= INT_MIN
			&& n.value <= INT_MAX
			);
	return (n);
}
