#include "push_swap.h"
#include <stdio.h>

void push(t_stack *src, t_stack *dst)
{
	if (src->size > 0)
		dst->data[dst->size] = src->data[src->size - 1];
	src->size--;
	dst->size++;
	printf("push\n");
}

void swap(t_stack *stack)
{
	int tmp;

	if (stack->size > 1)
	{
		tmp = stack->data[stack->size - 1];
		stack->data[stack->size - 1] = stack->data[stack->size - 2];
		stack->data[stack->size - 2] = tmp;
	}
	printf("swap\n");
}

void rotate(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->size > 1)
	{
		tmp = stack->data[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = tmp;
	}
	printf("rotate\n");
}

void reverse_rotate(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->size > 1)
	{
		tmp = stack->data[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->size - 1] = tmp;
	}
	printf("reverse rotate\n");
}
