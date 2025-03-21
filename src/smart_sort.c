/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:46:53 by thessena          #+#    #+#             */
/*   Updated: 2025/03/21 10:51:45 by thessena         ###   ########.fr       */
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

t_stack	*find_highest(t_stack **list)
{
	t_stack	*highest;
	t_stack	*current;

	highest = *list;
	current = *list;
	while (current)
	{
		if (current->value > highest->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack **list)
{
	t_stack	*lowest;
	t_stack	*current;
	
	lowest = *list;
	current = *list;
	while (current)
	{
		if (current->value < lowest->value)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	order_three(t_stack **list)
{
	t_stack *top_value = find_highest(list);
	if (top_value->index == 0)
		ra(list);
	else if (top_value->index == 1)
		rra(list);
	if (!is_in_order(list))
		sa(list);
}

void	assign_next_smaller(t_stack **main, t_stack **helper)
{
	t_stack	*m;
	t_stack	*h;
	int		smallest_diff;

	m = *main;
	while (main && *main)
	{
		h = *helper;
		smallest_diff = INT_MAX;
		(*main)->target = NULL;
		while (h)
		{
			if (h->value < (*main)->value && ((*main)->value - h->value) < smallest_diff)
			{
				smallest_diff = (*main)->value - h->value;
				(*main)->target = h;
			}
			h = h->next;
		}
		if (!(*main)->target)
			(*main)->target = find_highest(helper);
		main = &(*main)->next;
	}
}

void	assign_next_larger(t_stack **main, t_stack **helper)
{
	t_stack	*m;
	t_stack	*h;
	int		smallest_diff;

	m = *main;
	while (helper && *helper)
	{
		h = *main;
		smallest_diff = INT_MAX;
		(*helper)->target = NULL;
		while (h)
		{
			if (h->value > (*helper)->value && (h->value - (*helper)->value) < smallest_diff)
			{
				smallest_diff = h->value - (*helper)->value;
				(*helper)->target = h;
			}
			h = h->next;
		}
		if (!(*helper)->target)
			(*helper)->target = find_lowest(main);
		helper = &(*helper)->next;
	}
}

void	evalute_costs(t_stack **main, t_stack **helper)
{
	int		main_size;
	int		helper_size;
	t_stack	*current;
	int		main_cost;
	int		helper_cost;

	main_size = get_list_size(*main);
	helper_size = get_list_size(*helper);
	current = *main;
	while (current)
	{
		if (current->index <= main_size / 2)
			main_cost = current->index;
		else
			main_cost = main_size - current->index;
		if (current->target->index <= helper_size / 2)
			helper_cost = current->target->index;
		else
			helper_cost = helper_size - current->target->index;
		current->cost = main_cost + helper_cost;
		current = current->next;
	}
}
t_stack	*pick_best_move(t_stack **list)
{
	t_stack	*best;
	t_stack	*current;
	
	best = *list;
	current = *list;
	while (current)
	{
		if (current->cost < best->cost)
			best = current;
		current = current->next;
	}
	return (best);
}

void	transfer_to_helper(t_stack	**main, t_stack **helper)
{
	int		main_size;
	int		helper_size;
	t_stack	*best_move;

	main_size = get_list_size(*main);
	helper_size = get_list_size(*helper);
	evalute_costs(main, helper);
	best_move = pick_best_move(main);
}

position_smallest(t_stack **main)
{
	int		main_size;
	t_stack	*smallest;

	main_size = get_list_size(*main);
	smallest = find_lowest(main);
	if (smallest->index <= main_size / 2)
		while (smallest != *main)
			ra(main);
	else
		while (smallest != *main)
			rra(main);
}

void	smart_sort(t_stack **main, t_stack **helper)
{
	int		i;
	t_stack	*current;
	
	i = 0;
	current = *main;
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
	while (get_list_size(*main) > 3)
	{
		i = 0;
		current = *main;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		i = 0;
		current = *helper;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		assign_next_smaller(main, helper);
		print_stack(*main);
		pb(main, helper);
		printf("%s", "ich war hier");
	}
	order_three(main);
	while (*helper)
	{
		i = 0;
		current = *main;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		i = 0;
		current = *helper;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		assign_next_larger(main, helper);
		printf("%s", "ich war hier");
	}
	if (!is_in_order(main))
		position_smallest(main);
}
