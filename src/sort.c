/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:50:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/14 11:33:31 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	if (*a || (*a)->next || (*a)->next->next || (*a)->next->next->next)
	{
		top = (*a)->value;
		middle = (*a)->next->value;
		bottom = (*a)->next->next->value;
		if (top > middle && top > bottom) // 3 2 1 || 3 1 2
		{
			ra(a);
		}
		else if (middle > top && middle > bottom) // 2 3 1 || 1 3 2
		{
			sa(a);
			ra(a);
		}
		if ((*a)->value > (*a)->next->value) // 2 1 3
		{
			sa(a);
		}
	}
}
