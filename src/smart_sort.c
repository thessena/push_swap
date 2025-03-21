/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:46:53 by thessena          #+#    #+#             */
/*   Updated: 2025/03/21 17:20:05 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_in_order(t_stack **list)
{
	t_stack	*current = *list;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return 0;
		current = current->next;
	}
	return (1);
}

int	get_list_size(t_stack *list)
{
	int	size;
	
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_stack	*find_highest(t_stack **list)
{
	t_stack	*highest;
	t_stack	*current;

	highest = *list;
	current = *list;
	while (current)
	{
		if (current->value > highest->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack **list)
{
	t_stack	*lowest;
	t_stack	*current;
	
	lowest = *list;
	current = *list;
	while (current)
	{
		if (current->value < lowest->value)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	order_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	if (*a || (*a)->next || (*a)->next->next || (*a)->next->next->next)
	{
		top = (*a)->value;
		middle = (*a)->next->value;
		bottom = (*a)->next->next->value;
		if (top > middle && top > bottom)
		{
			ra(a);
		}
		else if (middle > top && middle > bottom)
		{
			sa(a);
			ra(a);
		}
		if ((*a)->value > (*a)->next->value)
		{
			sa(a);
		}
	}
}

void	assign_next_smaller(t_stack **main, t_stack **helper)
{
	t_stack	*h;
	int		smallest_diff;

	if (!*main || !*helper)
		return;
	while (*main)
	{
		h = *helper;
		smallest_diff = INT_MAX;
		(*main)->target = NULL;
		while (h)
		{
			if (h->value < (*main)->value && ((*main)->value - h->value) < smallest_diff)
			{
				smallest_diff = (*main)->value - h->value;
				(*main)->target = h;
			}
			h = h->next;
		}
		if (!(*main)->target)
			(*main)->target = find_highest(helper);
		main = &(*main)->next;
	}
}

void	assign_next_larger(t_stack **main, t_stack **helper)
{
	t_stack	*h;
	int		smallest_diff;

	if (!*main || !*helper)
		return;
	while (*helper)
	{
		h = *main;
		smallest_diff = INT_MAX;
		(*helper)->target = NULL;
		while (h)
		{
			if (h->value > (*helper)->value && (h->value - (*helper)->value) < smallest_diff)
			{
				smallest_diff = h->value - (*helper)->value;
				(*helper)->target = h;
			}
			h = h->next;
		}
		if (!(*helper)->target)
			(*helper)->target = find_lowest(main);
		helper = &(*helper)->next;
	}
}

void	evalute_costs(t_stack **main, t_stack **helper)
{
	int		main_size;
	int		helper_size;
	t_stack	*current;
	int		main_cost;
	int		helper_cost;

	main_size = get_list_size(*main);
	helper_size = get_list_size(*helper);
	current = *main;
	while (current)
	{
		if (current->index <= main_size / 2)
			main_cost = current->index;
		else
			main_cost = main_size - current->index;
		if (!current->target)
		{
			current->cost = main_cost;
			current = current->next;
			continue;
		}
		if (current->target->index <= helper_size / 2)
			helper_cost = current->target->index;
		else
			helper_cost = helper_size - current->target->index;
		current->cost = main_cost + helper_cost;
		current = current->next;
	}
}
t_stack	*pick_best_move(t_stack **list)
{
	t_stack	*best;
	t_stack	*current;
	
	best = *list;
	current = *list;
	if (!*list)
		return (NULL);
	while (current)
	{
		if (current->cost < best->cost)
			best = current;
		current = current->next;
	}
	return (best);
}

void	align_top(t_stack **main, t_stack **helper, t_stack *best)
{
	int	main_moves;
	int	helper_moves;
	
	main_moves = best->index;
	helper_moves = best->target->index;
	while (main_moves > 0 && helper_moves > 0)
	{
		rr(main, helper);
		main_moves--;
		helper_moves--;
	}
	while (main_moves > 0)
	{
		ra(main);
		main_moves--;
	}
	while (helper_moves > 0)
	{
		rb(helper);
		helper_moves--;
	}
}

void	align_bottom(t_stack **main, t_stack **helper, t_stack *best)
{
	int	main_size;
	int	helper_size;
	int	main_moves;
	int	helper_moves;
	
	main_size = get_list_size(*main);
	helper_size = get_list_size(*helper);
	main_moves = main_size - best->index;
	helper_moves = helper_size - best->target->index;
	while (main_moves > 0 && helper_moves > 0)
	{
		rrr(main, helper);
		main_moves--;
		helper_moves--;
	}
	while (main_moves > 0)
	{
		rra(main);
		main_moves--;
	}
	while (helper_moves > 0)
	{
		rrb(helper);
		helper_moves--;
	}
}

void	adjust_positions(t_stack **main, t_stack **helper, t_stack *best)
{
	int	main_size;
	int	helper_size;
	int	main_moves;
	int	helper_moves;

	main_size = get_list_size(*main);
	helper_size = get_list_size(*helper);
	main_moves = best->index;
	helper_moves = best->target->index;
	if (main_moves <= main_size / 2)
		while (main_moves > 0)
		{
			ra(main);
			main_moves--;
		}
	else
		while (main_moves < main_size)
		{
			rra(main);
			main_moves++;
		}
	if (helper_moves <= helper_size / 2)
		while (helper_moves > 0)
		{
			rb(helper);
			helper_moves--;
		}
	else
		while (helper_moves < helper_size)
		{
			rrb(helper);
			helper_moves++;
		}
}

void	transfer_to_helper(t_stack	**main, t_stack **helper)
{
	int		main_size;
	int		helper_size;
	t_stack	*best_move;

	main_size = get_list_size(*main);
	helper_size = get_list_size(*helper);
	if (!*main || !*helper)
		return;
	evalute_costs(main, helper);
	best_move = pick_best_move(main);
	if (best_move->index <= main_size / 2 && best_move->target->index <= helper_size / 2)
		align_top(main, helper, best_move);
	else if (best_move->index > main_size / 2 && best_move->target->index > helper_size / 2)
		align_bottom(main, helper, best_move);
	else
		adjust_positions(main, helper, best_move);
}

void	position_smallest(t_stack **main)
{
	int		main_size;
	t_stack	*smallest;

	main_size = get_list_size(*main);
	if (!*main)
		return;
	smallest = find_lowest(main);
	if (smallest->index <= main_size / 2)
		while (smallest != *main)
			ra(main);
	else
		while (smallest != *main)
			rra(main);
}

void	transfer_to_main(t_stack **main, t_stack **helper)
{
	int	main_size;
	
	main_size = get_list_size(*main);
	if (!*helper || !(*helper)->target)
	return;
	if ((*helper)->target->index <= main_size / 2)
		while ((*helper)->target != *main)
			ra(main);
	else
		while ((*helper)->target != *main)
			rra(main);
	pa(main, helper);
	position_smallest(main);
}

void	smart_sort(t_stack **main, t_stack **helper)
{
	int		i;
	t_stack	*current;
	
	if (!*main)
		return;
	i = 0;
	current = *main;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	if (is_in_order(main))
		return;
	if (!is_in_order(main) && get_list_size(*main) == 2)
	{
		sa(main);
		return;
	}
	pb(main, helper);
	pb(main, helper);
	while (get_list_size(*main) > 3)
	{
		i = 0;
		current = *main;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		i = 0;
		current = *helper;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		assign_next_smaller(main, helper);
		transfer_to_helper(main, helper);
		pb(main, helper);
		// printf("%s", "ich war hier");
	}
	order_three(main);
	while (*helper)
	{
		i = 0;
		current = *main;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		i = 0;
		current = *helper;
		while (current)
		{
			current->index = i++;
			current = current->next;
		}
		assign_next_larger(main, helper);
		transfer_to_main(main, helper);
		// printf("%s", "ich war hier");
	}
	if (!is_in_order(main))
		position_smallest(main);
}
