/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:33:16 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/03 15:57:21 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack/stack.h"
#include "push_swap_lang/language.h"

// int main(int ac, char **av)
// {
// 	if (ac == 1)
// 	{
// 		write(2, "Error\n", 6);
// 		exit(0);
// 	}
// 	if (ac == 2)
// 	return 0;
// }

#include <string.h>
#include <stdio.h>

void	print_stack(t_mystack *head)
{
	while (head)
	{
		printf("|\t%d\t|\n", head->data);
		head = head->next;
	}
	printf("__________________\n\n");
}

int main(int argc, char const *argv[])
{
	

	int i = 1;
	t_mystack *a;
	t_mystack *b;
	t_mystack *tail;
	
	t_mystack ***s;

	while (i < argc)
	{
		tail = append_stack(&a, tail, atoi(argv[i++]));
	}
	
	s = malloc(2 * sizeof(void *));
	
	print_stack(a);
	print_stack(b);
	
	// ra pb*3 (ra+pa)*2 ra*2 pa ra 
	
	s[0] = &a;
	s[1] = &b;
	
	ra(s);
	pb(s);
	pb(s);
	pb(s);
	
	
	ra(s);
	pa(s);
	ra(s);
	pa(s);
	
	
	ra(s);
	ra(s);
	
	
	pa(s);
	ra(s);
	
	
	print_stack(a);
	print_stack(b);
	
	return 0;
}


