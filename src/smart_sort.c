/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:46:53 by thessena          #+#    #+#             */
/*   Updated: 2025/03/19 11:21:50 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_in_order(t_stack **list)
{
	t_stack	*current = *list;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return 0;
		current = current->next;
	}
	return (1);
}

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

void	smart_sort(t_stack **main, t_stack **helper)
{
	int		i;
	t_stack	*current;
	
	i = 0;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	if (is_in_order(main))
		return;
	if (!is_in_order(main) && get_list_size(*main) == 2)
	{
		sa(main);
		return;
	}
	pb(main, helper);
	pb(main, helper);

}
