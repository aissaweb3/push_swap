/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:37:05 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 10:42:37 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

ssize_t	read_line(char *buffer)
{
	ssize_t			bytes_read;

	bytes_read = 0;
	while (buffer[bytes_read] != '\n')
		bytes_read += read(0, buffer, 1);
	buffer[bytes_read] = 0;
	return (bytes_read);
}
