/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/10 10:11:15 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack
{
	int *data;
	int size;
	int capacity;
} t_stack;

t_stack	*init_stack(int size, char **argv);
void	free_stack(t_stack *stack);
void	push_swap(t_stack *stack_a, t_stack *stack_b);

#endif
