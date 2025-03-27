/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 17:17:04 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int				cost;
}	t_stack;

t_stack	*create_node(int value);
void	append_node(t_stack **stack, int value);
int		is_valid_number(char *str);
int		has_duplicate(t_stack *stack, int value);
long	ft_atol(const char *str);
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

int		get_list_size(t_stack *list);
int		is_sorted(t_stack *list);
t_stack	*get_max_node(t_stack *list);
t_stack	*get_min_node(t_stack *list);
void	set_nearest_smaller_target(t_stack **a, t_stack **b);
void	set_nearest_bigger_target(t_stack **a, t_stack **b);
void	calc_cheapest(t_stack *a, t_stack *b);
t_stack	*get_cheapest_node(t_stack *list);
void	rotate_if_both_above_mid(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_if_both_below_mid(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_seperate(t_stack **a, t_stack **b, t_stack *cheapest);
void	sort_three(t_stack **list);
void	sort_four(t_stack **a, t_stack **b);
void	move_from_a_to_b(t_stack **a, t_stack **b);
void	move_from_b_to_a(t_stack **a, t_stack **b);
void	move_min_to_top(t_stack **a);
void	set_list_index(t_stack *list);
void	turk_sort(t_stack **a, t_stack **b);

#endif
