/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:35 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/16 13:44:32 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_strcat(char *dst, char *src)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
}

static int	calc_len(int ac, char **words)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < ac)
	{
		total_len += ft_strlen(words[i]);
		(i < ac - 1) && (total_len++);
		i++;
	}
	return (total_len);
}

char	*join_args(int ac, char **words)
{
	char	*sentence;
	int		total_len;
	int		j;

	if (ac == 0)
		return (NULL);
	total_len = calc_len(ac, words);
	sentence = (char *)malloc(total_len + 1);
	if (sentence == NULL)
		return (NULL);
	sentence[0] = '\0';
	j = 0;
	while (j < ac)
	{
		ft_strcat(sentence, words[j]);
		if (j < ac - 1)
			ft_strcat(sentence, " ");
		j++;
	}
	return (sentence);
}
