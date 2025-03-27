/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:01:46 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 19:02:36 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
