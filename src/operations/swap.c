/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:09:10 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 16:28:50 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a || (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
		set_list_index(*a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b || (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
		set_list_index(*b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	// write(1, "ss\n", 3);
}
