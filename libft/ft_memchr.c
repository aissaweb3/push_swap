/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:10:51 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/11/18 13:07:20 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*casted;

	i = 0;
	casted = (char *)s;
	while (i < n)
	{
		if (casted[i] == (char)c)
			return (casted + i);
		i++;
	}
	return (NULL);
}
