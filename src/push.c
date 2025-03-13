/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:26:26 by thessena          #+#    #+#             */
/*   Updated: 2025/03/13 19:36:41 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		write(1, "pb\n", 3);
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		write(1, "pa\n", 3);
	}
}
