/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:16 by thessena          #+#    #+#             */
/*   Updated: 2025/03/19 17:49:19 by thessena         ###   ########.fr       */
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
int		find_position_in_a(t_stack *a, int value);
int		find_position_in_b(t_stack *b, int value);
void	turk_sort(t_stack **a, t_stack **b);
void	rotate_to_position(t_stack **a, t_stack **b, int pos_a, int pos_b, int a_size, int b_size);
int		stack_max(t_stack *stack);

void	smart_sort(t_stack **main, t_stack **helper);
void	assign_next_smaller(t_stack **main, t_stack **helper);
void	order_three(t_stack **list);
t_stack	*find_lowest(t_stack **list);
t_stack	*find_highest(t_stack **list);
int		get_list_size(t_stack *list);
int		is_in_order(t_stack **list);

void	basic_sort(t_stack **main, t_stack **helper);


#endif
