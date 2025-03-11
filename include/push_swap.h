/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/11 11:07:26 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int 	data;
	int 	size;
	int 	capacity;
} t_stack;

typedef struct s_stack_node
{
	int 				data;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	s_stack_node;

void	init_stack(t_stack **a, char **argv);
void	free_stack(t_stack *stack);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *src, t_stack *dst);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
