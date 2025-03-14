/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/14 16:36:30 by thessena         ###   ########.fr       */
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

void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_three(t_stack **a);
int		find_min(t_stack *stack);
void	move_min_to_top(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		find_position_in_b(t_stack *b, int value);
void	turk_sort(t_stack **a, t_stack **b);

#endif
