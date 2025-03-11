/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/03/11 15:23:46 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	init_stack(t_stack **a, char **argv)
{
	int	n;
	int	i;

	i = 0;
	while(argv[i])
	{
		n = atoi(argv[i]);
		append_node(a, n);
		i++;
	}
}

/* void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
} */

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	printf("stack_a: %d\n", stack_a->size);
	printf("stack_b: %d\n", stack_b->size);
	swap(stack_a);
	printf("stack_a: %d\n", stack_a->size);
	printf("stack_b: %d\n", stack_b->size);
	rotate(stack_a);
	printf("stack_a: %d\n", stack_a->size);
	printf("stack_b: %d\n", stack_b->size);
	reverse_rotate(stack_a);
	printf("stack_a: %d\n", stack_a->size);
	printf("stack_b: %d\n", stack_b->size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		printf("Usage: %s [integers]\n", argv[0]);
		return (1);
	}
	init_stack(&a, argv + 1);
	init_stack(&b, NULL);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
