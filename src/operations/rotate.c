/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:27:34 by thessena          #+#    #+#             */
/*   Updated: 2025/03/28 10:50:30 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a || (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		set_list_index(*a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*b || (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		set_list_index(*b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
} */

static void	rotate_forward(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	set_list_index(*stack);
}

void	ra(t_stack **a)
{
	if (*a && (*a)->next)
	{
		rotate_forward(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	if (*b && (*b)->next)
	{
		rotate_forward(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	int	a_valid = *a && (*a)->next;
	int	b_valid = *b && (*b)->next;

	if (a_valid && b_valid)
	{
		rotate_forward(a);
		rotate_forward(b);
		write(1, "rr\n", 3);
	}
	else
	{
		if (a_valid)
			ra(a);
		if (b_valid)
			rb(b);
	}
}
