/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/01/15 13:58:43 by thessena         ###   ########.fr       */
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
	stack->size = size;
	return (stack);
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
	return (0);
}
