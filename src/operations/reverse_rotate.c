/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:27:52 by thessena          #+#    #+#             */
/*   Updated: 2025/08/29 13:07:06 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*a || (*a)->next)
	{
		tmp = *a;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *a;
		*a = tmp;
		set_list_index(*a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*b || (*b)->next)
	{
		tmp = *b;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *b;
		*b = tmp;
		set_list_index(*b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
} */

static void	rotate_reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	set_list_index(*stack);
}

void	rra(t_stack **a)
{
	if (*a && (*a)->next)
	{
		rotate_reverse(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	if (*b && (*b)->next)
	{
		rotate_reverse(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	int	a_valid;
	int	b_valid;

	a_valid = *a && (*a)->next;
	b_valid = *b && (*b)->next;
	if (a_valid && b_valid)
	{
		rotate_reverse(a);
		rotate_reverse(b);
		write(1, "rrr\n", 4);
	}
	else
	{
		if (a_valid)
			rra(a);
		if (b_valid)
			rrb(b);
	}
}
