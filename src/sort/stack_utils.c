/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:04 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 19:04:32 by thessena         ###   ########.fr       */
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

t_stack	*get_cheapest_node(t_stack *list)
{
	t_stack	*cheapest;
	t_stack	*current;

	cheapest = list;
	current = list;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
