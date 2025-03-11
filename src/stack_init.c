/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:23:29 by thessena          #+#    #+#             */
/*   Updated: 2025/03/11 17:21:18 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void append_node(t_stack **stack, int n)
{
	t_stack		*node;
	t_stack 	*last_node;
	
	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->data = n;
}
