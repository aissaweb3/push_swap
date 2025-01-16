/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:17:43 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/16 14:44:17 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

t_mystack	*push_arg(int i, char **av, t_mystack **head)
{
	static t_mystack	*tail;
	t_arg				arg;

	arg = validate_arg(av[i]);
	if (!arg.is_valid)
		return (free_split(av), free_stack(head), NULL);
	check_dup(*head, &arg);
	if (arg.is_uniq == NOT_UNIQ)
		return (free_split(av), free_stack(head), NULL);
	tail = push_elem(head, tail, arg.value);
	if (tail == NULL)
		return (free_split(av), free_stack(head), NULL);
	return (*head);
}

t_mystack	*init_stack(int ac, char **av)
{
	char		**args;
	int			i;
	t_mystack	*head;
	t_mystack	*tail;

	1 && (av++, ac--, i = 0, head = NULL);
	args = ft_split(join_args(ac, av), ' '); // to be free
	if (args == NULL)
		return (NULL);
	ac = 0;
	while (args[ac])
		ac++;
	while (i < ac)
	{
		tail = push_arg(i, args, &head);
		if (tail == NULL)
			return (NULL);
		i++;
	}
	free_split(args);
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
