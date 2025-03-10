/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/03/10 15:34:14 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_stack	*init_stack(int size, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(sizeof(int) * size);
	if(!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->capacity = size;
	if (size)
	{
		while (--size >= 0)
			stack->data[size] = atoi(argv[size]);
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
}

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
	if (argc < 2)
	{
		printf("Usage: %s [integers]\n", argv[0]);
		return (1);
	}

	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack(argc - 1, &argv[1]);
	stack_b = init_stack(0, NULL);
	if (!stack_a || !stack_b)
	{
		printf("Error: Stack initialization failed\n");
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
