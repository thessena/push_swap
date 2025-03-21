/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/03/21 17:48:27 by thessena         ###   ########.fr       */
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
