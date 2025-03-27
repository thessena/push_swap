/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 17:06:16 by thessena         ###   ########.fr       */
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

t_stack *get_max_node(t_stack *list)
{
    t_stack *max;

    max = list;
    while (list)
    {
        if (list->value > max->value)
            max = list;
        list = list->next;
    }
    return (max);
}

t_stack *get_min_node(t_stack *list)
{
	t_stack *min;

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

		if (current->target)
		{
			if (current->target->index <= size_b / 2)
				cost_b = current->target->index;
			else
				cost_b = size_b - current->target->index;
		}
		else
			cost_b = 0;
		current->cost = cost_a + cost_b;
		current = current->next;
	}
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

void	rotate_if_both_above_mid(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
		rr(a, b);
	while (cheapest != *a)
		ra(a);
	while (cheapest->target != *b)
		rb(b);
}

void	rotate_if_both_below_mid(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
		rrr(a, b);
	while (cheapest != *a)
		rra(a);
	while (cheapest->target != *b)
		rrb(b);
}

void	rotate_seperate(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	size_a;
	int	size_b;

	size_a = get_list_size(*a);
	size_b = get_list_size(*b);
	if (cheapest->index <= size_a / 2)
		while (cheapest != *a)
			ra(a);
	else
		while (cheapest != *a)
			rra(a);
	if (cheapest->target->index <= size_b / 2)
		while (cheapest->target != *b)
			rb(b);
	else
		while (cheapest->target != *b)
			rrb(b);
}

void	sort_three(t_stack **list)
{
	int top = (*list)->value;
	int middle = (*list)->next->value;
	int bottom = (*list)->next->next->value;

	if (top > middle && middle < bottom && top < bottom)
		sa(list);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(list);
		rra(list);
	}
	else if (top > middle && top > bottom && middle < bottom)
		ra(list);
	else if (top < middle && middle > bottom && top > bottom)
		rra(list);
	else if (top < middle && middle > bottom && top < bottom)
	{
		rra(list);
		sa(list);
	}
}

void sort_four(t_stack **a, t_stack **b)
{
	t_stack *current = *a;
	int min = current->value;
	int min_pos = 0;
	int pos = 0;

	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	if (!is_sorted(*a))
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
}

void	move_from_a_to_b(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;
	t_stack	*cheapest;

	size_a = get_list_size(*a);
	size_b = get_list_size(*b);
	calc_cheapest(*a, *b);
	cheapest = get_cheapest_node(*a);
	if (cheapest->index <= size_a / 2 && cheapest->target->index <= size_b / 2)
		rotate_if_both_above_mid(a, b, cheapest);
	else if (cheapest->index > size_a / 2 && cheapest->target->index > size_b / 2)
		rotate_if_both_below_mid(a, b, cheapest);
	else
		rotate_seperate(a, b, cheapest);
}

void	move_from_b_to_a(t_stack **a, t_stack **b)
{
	int	size_a;

	if (!*b || !(*b)->target)
		return ;
	size_a = get_list_size(*a);
	if ((*b)->target->index <= size_a / 2)
		while ((*b)->target != *a)
			ra(a);
	else
		while ((*b)->target != *a)
			rra(a);
	pa(a, b);
}

void	move_min_to_top(t_stack **a)
{
	int		size_a;
	t_stack	*min;

	size_a = get_list_size(*a);
	min = get_min_node(*a);
	if (min->index <= size_a / 2)
		while (min != *a)
			ra(a);
	else
		while (min != *a)
			rra(a);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	// int		i;
	// t_stack	*current;

	if (is_sorted(*a))
		return ;
	if (get_list_size(*a) == 2)
	{
		sa(a);
		return;
	}
	if (get_list_size(*a) == 3)
	{
		sort_three(a);
		return;
	}
	if (get_list_size(*a) == 4)
	{
		sort_four(a, b);
		return;
	}
/* 	i = 0;
	current = *a;
	while (current)
	{
		current->index = i++;
		current = current->next;
	} */
	if (get_list_size(*a) > 3)
		pb(a, b);
	if (get_list_size(*a) > 3)
		pb(a, b);
	while (get_list_size(*a) > 3)
	{
/* 		i = 0;
		current = *a;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		i = 0;
		current = *b;
		while (current)
		{
			current->index = i++;
			current = current->next;
		} */
		set_nearest_smaller_target(a, b);
		move_from_a_to_b(a, b);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
/* 		i = 0;
		current = *a;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		i = 0;
		current = *b;
		while (current)
		{
			current->index = i++;
			current = current->next;
		} */
		set_nearest_bigger_target(a, b);
		move_from_b_to_a(a, b);
	}
	if (!is_sorted(*a))
		move_min_to_top(a);
}
