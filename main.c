/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:33:16 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 14:01:31 by ioulkhir         ###   ########.fr       */
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


// int main(int argc, char const *argv[])
// {
	

// 	int i = 1;
// 	t_mystack *a;
// 	t_mystack *b;
// 	t_mystack *tail;
	
// 	t_mystack ***s;

// 	while (i < argc)
// 	{
// 		tail = append_stack(&a, tail, atoi(argv[i++]));
// 	}
	
// 	s = malloc(2 * sizeof(void *));
	
// 	print_stack(a);
// 	print_stack(b);
	
// 	// ra pb*3 (ra+pa)*2 ra*2 pa ra 
	
// 	s[0] = &a;
// 	s[1] = &b;
	
// 	ra(s);
// 	pb(s);
// 	pb(s);
// 	pb(s);
	
	
// 	ra(s);
// 	pa(s);
// 	ra(s);
// 	pa(s);
	
	
// 	ra(s);
// 	ra(s);
	
	
// 	pa(s);
// 	ra(s);
	
	
// 	print_stack(a);
// 	print_stack(b);
	
// 	return 0;
// }



#include "algorithm/algorithm.h"

static void	validation_error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

// static void	malloc_error(void)
// {
// 	write(2, "Malloc Error !\n", 16);
// 	exit(EXIT_FAILURE);
// }

void	print_stack(t_mystack *head)
{
	while (head)
	{
		printf("|\t%d\t%d\t(%d, %d)\t\t|\n", head->data, head->index, head->push_cost_b, head->push_cost_a);
		head = head->next;
	}
	printf("________________________________\n\n");

}

void	my_sort(t_mystack **s[2])
{
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
}

int main(int ac, char **av)
{
	t_parsed_data	my_data;
	t_mystack		**a_b[2]; // both stackes

	my_data = get_my_data(ac, av);
	if (my_data.validation_error == ERR)
		validation_error();
	a_b[0] = &my_data.stack_a;
	a_b[1] = &my_data.stack_b;
	
	
	
	
	// print_stack(my_data.stack_a);
	
	
	my_algo(&my_data, a_b);
	
	// print_stack(my_data.stack_a);
	// print_stack(my_data.stack_b);
	
	
	return 0;
	my_sort(a_b);
	return 0;
}


