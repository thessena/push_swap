/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/03/17 18:22:20 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_position_in_a(t_stack *a, int value)
{
	int	pos;
	t_stack	*tmp;

	pos = 0;
	tmp = a;
	while (tmp && tmp->value < value)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

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

void	rotate_to_position(t_stack **a, t_stack **b, int pos_a, int pos_b, int a_size, int b_size)
{
	if (pos_a > 0 && pos_b > 0 && pos_a <= a_size / 2 && pos_b <= b_size / 2)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b);
			pos_a--;
			pos_b--;
		}
	}
	else if (pos_a > a_size / 2 && pos_b > b_size / 2)
	{
		int	steps_a = a_size - pos_a;
		int	steps_b = b_size - pos_b;
		while (steps_a > 0 && steps_b > 0)
		{
			rrr(a, b);
			steps_a--;
			steps_b--;
		}
	}
	if (pos_a > 0)
	{
		if (pos_a <= a_size / 2)
		{
			while (pos_a > 0)
			{
				ra(a);
				pos_a--;
			}
		}
		else
		{
			int	steps = a_size - pos_a;
			while (steps > 0)
			{
				rra(a);
				steps--;
			}
		}
	}
	if (pos_b > 0)
	{
		if (pos_b <= b_size / 2)
		{
			while (pos_b / 2)
			{
				rb(b);
				pos_b--;
			}
		}
		else
		{
			int	steps = b_size - pos_b;
			while (steps > 0)	
			{
				rrb(b);
				steps--;
			}
		}
		
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	value;
	int	a_size;
	int	b_size;
	int	pos_a;
	int	pos_b;

	size = stack_size(*a);
	if (size <= 1) return;
	if (size == 2 && (*a)->value > (*a)->next->value) { sa(a); return;	}
	if (size == 3) { sort_three(a); return;	}
	if (size == 4) { sort_four(a, b); return; }
	if (size == 5) { sort_five(a, b); return; }
	pb(a, b);
	pb(a, b);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b);
	while (stack_size(*a) > 3)
	{
		value = (*a)->value;
		pos_b = find_position_in_b(*b, value);
		b_size = stack_size(*b);
		a_size = stack_size(*a);
		pos_a = 0;
		rotate_to_position(a, b, pos_a, pos_b, a_size, b_size);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		value = (*b)->value;
		pos_a = find_position_in_a(*a, value);
		a_size = stack_size(*a);
		b_size = stack_size(*b);
		pos_b = 0;
		rotate_to_position(a, b, pos_a, pos_b, a_size, b_size);
		pa(a, b);
		if (pos_a > 0)
        {
            if (pos_a <= a_size / 2)
            {
                while (pos_a > 0)
                {
                    rra(a);
                    pos_a--;
                }
            }
            else
            {
                int steps = a_size + 1 - pos_a;
                while (steps > 0)
                {
                    ra(a);
                    steps--;
                }
            }
        }
	}
}
