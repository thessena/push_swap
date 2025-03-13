/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:09:10 by thessena          #+#    #+#             */
/*   Updated: 2025/03/13 19:12:59 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if(*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		write(1, "pb\n", 3);
	}

}
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if(*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		write(1, "pa\n", 3);
	}
}

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if(*a || (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if(*b || (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
		write(1, "sb\n", 3);
	}
}

/* void push(t_stack *src, t_stack *dst)
{
	printf("push\n");
}

void swap(t_stack *stack)
{
	printf("swap\n");
}

void rotate(t_stack *stack)
{
	printf("rotate\n");
}

void reverse_rotate(t_stack *stack)
{
	printf("reverse rotate\n");
} */
