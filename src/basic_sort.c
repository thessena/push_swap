/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:50:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/14 19:37:16 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	if (*a || (*a)->next || (*a)->next->next || (*a)->next->next->next)
	{
		top = (*a)->value;
		middle = (*a)->next->value;
		bottom = (*a)->next->next->value;
		if (top > middle && top > bottom)
		{
			ra(a);
		}
		else if (middle > top && middle > bottom)
		{
			sa(a);
			ra(a);
		}
		if ((*a)->value > (*a)->next->value)
		{
			sa(a);
		}
	}
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	move_min_to_top(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		pos;
	int		size;
	int		i;

	tmp = *a;
	min = find_min(*a);
	pos = 0;
	size = stack_size(*a);
	i = 0;
	while (tmp && tmp->value != min)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(a);
			i++;
		}
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (*a || stack_size(*a) == 4)
	{
		move_min_to_top(a);
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (*a || stack_size(*a) == 5)
	{
		move_min_to_top(a);
		pb(a, b);
		move_min_to_top(a);
		pb(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
