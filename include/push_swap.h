/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/12 17:31:33 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*create_node(int value);
void	append_node(t_stack **stack, int value);
int		is_valid_number(char *str);
int		has_duplicate(t_stack *stack, int value);
long	ft_atoi(const char *str);
t_stack	*init_stack(int argc, char **argv);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

/* void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *src, t_stack *dst);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack); */

#endif
