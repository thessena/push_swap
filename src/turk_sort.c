/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/03/14 19:39:18 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_position_in_b(t_stack *b, int value)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = b;
	while (tmp && tmp->value > value)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_max_position(t_stack *b)
{
	int		max;
	int		pos;
	t_stack	*tmp;

	max = stack_max(b);
	pos = 0;
	tmp = b;
	while (tmp && tmp->value != max)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	rotate_to_max(t_stack **b, int b_size)
{
	int	pos;
	int	steps;

	pos = find_max_position(*b);
	if (pos <= b_size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		steps = b_size - pos;
		while (steps > 0)
		{
			rrb(b);
			steps--;
		}
	}
}

void	rotate_to_position(t_stack **b, int pos, int b_size)
{
	int	i;

	if (pos <= b_size / 2)
	{
		i = pos;
		while (i > 0)
		{
			rb(b);
			i--;
		}
	}
	else
	{
		i = b_size - pos;
		while (i > 0)
		{
			rrb(b);
			i--;
		}
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	value;
	int	pos;
	int	b_size;

	size = stack_size(*a);
	if (size <= 1)
		return;
	if (size == 2 && (*a)->value > (*a)->next->value)
	{
		sa(a);
		return;
	}
	if (size == 3)
	{
		sort_three(a);
		return;
	}
	if (size == 4)
	{
		sort_four(a, b);
		return;
	}
	if (size == 5)
	{
		sort_five(a, b);
		return;
	}
	pb(a, b);
	pb(a, b);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b);
	while (stack_size(*a) > 0)
	{
		value = (*a)->value;
		pos = find_position_in_b(*b, value);
		b_size = stack_size(*b);
		rotate_to_position(b, pos, b_size);
		pb(a, b);
		rotate_to_max(b, stack_size(*b));
	}
	while (*b)
		pa(a, b);
}

int	stack_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
