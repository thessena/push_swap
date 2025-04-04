/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:09:10 by thessena          #+#    #+#             */
/*   Updated: 2025/03/28 10:50:55 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a || (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
		set_list_index(*a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b || (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
		set_list_index(*b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
} */

static void	swap_top(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	set_list_index(*stack);
}

void	sa(t_stack **a)
{
	if (*a && (*a)->next)
	{
		swap_top(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	if (*b && (*b)->next)
	{
		swap_top(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	int	a_valid = *a && (*a)->next;
	int	b_valid = *b && (*b)->next;

	if (a_valid && b_valid)
	{
		swap_top(a);
		swap_top(b);
		write(1, "ss\n", 3);
	}
	else
	{
		if (a_valid)
			sa(a);
		if (b_valid)
			sb(b);
	}
}
