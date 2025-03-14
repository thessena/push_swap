/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/03/14 19:07:37 by thessena         ###   ########.fr       */
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
	if ((*b)->value < (*b)->next->value)
		sb(b);
	while (stack_size(*a) > 0)
	{
		value = (*a)->value;
		pos = find_position_in_b(*b, value);
		b_size = stack_size(*b);
		if (pos <= b_size / 2)
		{
			while (pos > 0)
			{
				rb(b);
				pos--;
			}
			pb(a, b);
		}
		else
		{
			while (b_size - pos > 0)
			{
				rrb(b);
				pos--;
			}
			pb(a, b);
		}
		while (*b && (*b)->next && (*b)->value < (*b)->next->value)
			sb(b);
	}
	while (*b)
		pa(a, b);
}
