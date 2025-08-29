/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:20:00 by thessena          #+#    #+#             */
/*   Updated: 2025/08/29 13:20:00 by thessena         ###   ########.fr       */
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
	if (is_sorted(*a))
		return ;
	move_min_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}
