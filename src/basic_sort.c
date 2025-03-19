/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:01:06 by thessena          #+#    #+#             */
/*   Updated: 2025/03/19 17:12:28 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_elements(t_stack *list)
{
	int	count;
	
	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

int	is_sortet_basic(t_stack **list)
{
	t_stack	*current;

	current = *list;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_small(t_stack **list)
{
	t_stack	*current;
	t_stack	*max_node;

	current = *list;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	if (max_node == *list)
		ra(list);
	else if (max_node == (*list)->next)
		rra(list);
	if ((*list)->value > (*list)->next->value)
		sa(list);
}

void	move_smallest_front(t_stack **list)
{
	t_stack *current;
	t_stack	*min_node;
	int		size;
	int		min_pos;
	int		pos;

	current = *list;
	min_node = current;
	size = count_elements(*list);
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_node->value)
		{
			min_node = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (min_pos <= size / 2)
		while (min_node != *list)
			ra(list);
	else
		while (min_node != *list)
			rra(list);
}


