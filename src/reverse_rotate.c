/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:27:52 by thessena          #+#    #+#             */
/*   Updated: 2025/03/21 19:10:19 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*a || (*a)->next)
	{
		tmp = *a;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *a;
		*a = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*b || (*b)->next)
	{
		tmp = *b;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *b;
		*b = tmp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
