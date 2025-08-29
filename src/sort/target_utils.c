/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:55 by thessena          #+#    #+#             */
/*   Updated: 2025/08/29 13:18:45 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_nearest_smaller_target(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		min_diff;

	current_a = *a;
	while (current_a)
	{
		current_b = *b;
		min_diff = INT_MAX;
		current_a->target = NULL;
		while (current_b)
		{
			if (current_b->value < current_a->value && \
				(current_a->value - current_b->value) < min_diff)
			{
				min_diff = current_a->value - current_b->value;
				current_a->target = current_b;
			}
			current_b = current_b->next;
		}
		if (!current_a->target)
			current_a->target = get_max_node(*b);
		current_a = current_a->next;
	}
}

void	set_nearest_bigger_target(t_stack **a, t_stack **b)
{
	t_stack	*current_b;
	t_stack	*current_a;
	int		min_diff;

	current_b = *b;
	while (current_b)
	{
		current_a = *a;
		min_diff = INT_MAX;
		current_b->target = NULL;
		while (current_a)
		{
			if (current_a->value > current_b->value && \
				(current_a->value - current_b->value) < min_diff)
			{
				min_diff = current_a->value - current_b->value;
				current_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (!current_b->target)
			current_b->target = get_min_node(*a);
		current_b = current_b->next;
	}
}

void	calc_cheapest(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*current;
	int		cost_a;
	int		cost_b;

	size_a = get_list_size(a);
	size_b = get_list_size(b);
	current = a;
	while (current)
	{
		if (current->index <= size_a / 2)
			cost_a = current->index;
		else
			cost_a = size_a - current->index;
		if (current->target && current->target->index <= size_b / 2)
			cost_b = current->target->index;
		else if (current->target)
			cost_b = size_b - current->target->index;
		else
			cost_b = 0;
		current->cost = cost_a + cost_b;
		current = current->next;
	}
}
