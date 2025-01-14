/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:42:01 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/11/18 13:21:14 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pin;

	i = 0;
	pin = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			pin = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		pin = (char *)(s + i);
	return (pin);
}
