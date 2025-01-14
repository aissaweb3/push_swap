/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:17:43 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/14 13:45:01 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	free_split(char **av, char used_split)
{
	int	i;

	if (!used_split)
		return ;
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

t_mystack	*push_arg(int i, char **av, int used_split, t_mystack **head)
{
	t_arg		arg;
	t_mystack	*tail;

	arg = validate_arg(av[i]);
	if (!arg.is_valid)
		return (free_split(av, used_split), free_stack(head), NULL);
	check_dup(*head, &arg);
	if (arg.is_uniq == NOT_UNIQ)
		return (free_split(av, used_split), free_stack(head), NULL);
	tail = NULL;
	tail = push_elem(head, tail, arg.value);
	if (tail == NULL)
		return (free_split(av, used_split), free_stack(head), NULL);
	return (*head);
}

t_mystack	*init_stack(int ac, char **av)
{
	int			i;
	t_mystack	*head;
	t_mystack	*tail;
	char		used_split;

	1 && (av++, ac--, i = 0, head = NULL, used_split = 0);
	if (ac == 1)
	{
		av = ft_split(av[0], ' ');
		if (av == NULL)
			return (NULL);
		used_split = 1;
		ac = 0;
		while (av[ac])
			ac++;
	}
	while (i < ac)
	{
		tail = push_arg(i, av, used_split, &head);
		if (tail == NULL)
			return (NULL);
		i++;
	}
	free_split(av, used_split);
	return (head);
}

void	index_stack_a(t_mystack *a)
{
	t_mystack	*curr;
	t_mystack	*min_node;
	int			min_value;
	int			i;

	i = -1;
	while (1)
	{
		curr = a;
		min_node = NULL;
		min_value = INT_MAX;
		while (curr)
		{
			if (curr->index == NOT_SET && curr->data < min_value)
			{
				min_value = curr->data;
				min_node = curr;
			}
			curr = curr->next;
		}
		i++;
		if (min_node == NULL)
			break ;
		min_node->index = i;
	}
}
