/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:48:24 by thessena          #+#    #+#             */
/*   Updated: 2025/03/26 16:10:39 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Weise jedem Element einen Index basierend auf seiner Größe zu
void	assign_indices(t_stack **stack_a)
{
	t_stack *current = *stack_a;
	t_stack *compare;
	int index;

	while (current)
	{
		index = 0;
		compare = *stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	ft_sqrt(int n)
{
	int	sqr;

	sqr = 0;
	while (sqr * sqr <= n && n > 0)
	{
		if ((sqr + 1) * (sqr + 1) >= n)
			return (sqr);
		sqr++;
	}
	return (0);
}

// Schiebe Elemente von stack_a nach stack_b in Gruppen
void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int count = 0;
	int range = ft_sqrt(stack_size(*stack_a)) * 1.6; // Gruppengröße

	while (*stack_a)
	{
		if ((*stack_a)->index <= count)
		{
			pb(stack_a, stack_b); // Schiebe nach stack_b
			rb(stack_b);          // Rotiere stack_b
			count++;
		}
		else if ((*stack_a)->index < count + range)
		{
			pb(stack_a, stack_b); // Schiebe nach stack_b
			count++;
		}
		else
		{
			ra(stack_a); // Rotiere stack_a, um später zu bearbeiten
		}
	}
}

// Finde die Position des größten Elements in stack_b
int	find_max_position(t_stack *stack_b)
{
	t_stack *temp = stack_b;
	int max_value = temp->value;
	int max_pos = 0;
	int pos = 0;

	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (max_pos);
}

// Berechne die effizientesten Bewegungen für stack_b
int calculate_moves(t_stack *stack_b)
{
    int max_pos = find_max_position(stack_b);
    int size = stack_size(stack_b);
    int forward = max_pos;
    int reverse = size - max_pos;

    if (forward <= reverse)
        return (forward);  // Positive Zahl: vorwärts rotieren
    return (-reverse);     // Negative Zahl: rückwärts rotieren
}

// Schiebe Elemente von stack_b zurück nach stack_a
void move_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int moves;

    while (*stack_b)
    {
        moves = calculate_moves(*stack_b);
        if (moves >= 0)
        {
            while (moves--)
                rb(stack_b); // Rotiere vorwärts
        }
        else
        {
            moves = -moves;
            while (moves--)
                rrb(stack_b); // Rotiere rückwärts
        }
        pa(stack_a, stack_b); // Schiebe zurück nach stack_a
    }
}

void	sorting_start(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 5)
	{
		if (size == 2)
			sa(stack_a);
		if (size == 3)
			sort_three(stack_a);
		if (size == 4)
			sort_four(stack_a, stack_b);
		return ;
	}
	else
		ksort(stack_a, stack_b);
}

void	ksort(t_stack **stack_a, t_stack **stack_b)
{
	assign_indices(stack_a);
	move_to_b(stack_a, stack_b);
	move_to_a(stack_a, stack_b);
}
