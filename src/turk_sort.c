/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/03/21 17:51:48 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_list_size(t_stack *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int	is_sorted(t_stack *list)
{
	while (list && list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

t_stack	*get_max_node(t_stack *list)
{
	t_stack	*max;

	max = list;
	while (list)
	{
		if (list->value > max->value)
			max = list;
		list = list->next;
	}
	return (max);
}

t_stack	*get_min_node(t_stack *list)
{
	t_stack	*min;

	min = list;
	while (list)
	{
		if (list->value < min->value)
			min = list;
		list = list->next;
	}
	return (min);
}

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
			if (current_b->value < current_a->value && (current_a->value - current_b->value) < min_diff)
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
			if (current_a->value > current_b->value && (current_a->value - current_b->value) < min_diff)
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
