/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/03/12 15:01:03 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = create_node(value);
	if (!new_node)
		return ();
	if (!*stack)
	{
		*stack = new_node;
		return ();
	}
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new_node;
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

long	ft_atoi(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	*error = 0;
	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX || result < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return (sign * result);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		num;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		num = atoi(argv[i]);
		if (has_duplicate(a, num))
		{
			free_stack(a);
			return (NULL);
		}
		append_node(&a, num);
		i++;
	}
	return (a);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	a = NULL;
	b = NULL;
	a = init_stack(argc, argv);
	if (!a)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	free_stack(a);
	return (0);
}
