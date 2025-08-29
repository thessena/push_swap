/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:51 by thessena          #+#    #+#             */
/*   Updated: 2025/08/28 17:01:00 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **list)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*list)->value;
	middle = (*list)->next->value;
	bottom = (*list)->next->next->value;
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

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		min;
	int		min_pos;
	int		pos;

	current = *a;
	min = current->value;
	min_pos = 0;
	pos = 0;
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

void	handle_large_sort(t_stack **a, t_stack **b)
{
	if (get_list_size(*a) > 3)
		pb(a, b);
	if (get_list_size(*a) > 3)
		pb(a, b);
	while (get_list_size(*a) > 3)
	{
		set_nearest_smaller_target(a, b);
		move_from_a_to_b(a, b);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_nearest_bigger_target(a, b);
		move_from_b_to_a(a, b);
	}
	if (!is_sorted(*a))
		move_min_to_top(a);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if (get_list_size(*a) == 2)
	{
		sa(a);
		return ;
	}
	if (get_list_size(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	if (get_list_size(*a) == 4)
	{
		sort_four(a, b);
		return ;
	}
	handle_large_sort(a, b);
}
