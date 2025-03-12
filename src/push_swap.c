/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/03/12 13:24:17 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

/* void	init_stack(t_stack **a, char **argv)
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
} */

/* void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
} */

/* void push_swap(t_stack *stack_a, t_stack *stack_b)
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
} */

t_stack *create_node(int value)
{
	t_stack	*new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if(!new_node)
		return(NULL);
	new_node->value = value;
	new_node->next = NULL;
	return(new_node);
}

void append_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = create_node(value);
	if(!new_node)
		return;
	if(!*stack)
	{
		*stack = new_node;
		return;
	}
	last = *stack;
	while(last->next)
	{
		last = last->next;
	}
	last->next = new_node;
}

t_stack *init_stack(int argc, char **argv)
{
	t_stack	*a;
	int	i;
	int	num;
	
	a = NULL;
	i = 1;
	while(i < argc)
	{
		num = atoi(argv[i]);
		append_node(&a, num);
		i++;
	}
	return(a);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while(stack)
	{
		stack = stack->next;
		size++;
	}
	return(size);
}

void free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while(stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return(1);
	}
	a = NULL;
	b = NULL;
	a = init_stack(argc, argv);
	if(!a)
	{
		write(1, "Error\n", 6);
		return(1);
	}
	free_stack(a);
	return (0);
}
