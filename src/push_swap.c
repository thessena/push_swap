/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/03/12 16:36:55 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/push_swap.h"

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
		return;
	if (!*stack)
	{
		*stack = new_node;
		return;
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
	long	num;
	int		error;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(a);
			return (NULL);
		}
		num = (int)ft_atoi(argv[i], &error);
		if (error)
		{
			free_stack(a);
			return (NULL);
		}
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

void	print_stack(t_stack *stack)
{
	int		i;
	int		n;
	char	num[12];

	while (stack)
	{
		i = 0;
		n = stack->value;
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n == 0)
		{
			num[i] = '0';
			i++;
		}
		while (n > 0)
		{
			num[i] = (n % 10) + '0';
			i++;
			n = n / 10;
		}
		while (i > 0)
		{
			i--;
			write(1, &num[i], 1);
		}
		write(1, "\n", 1);
		stack = stack->next;
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
	print_stack(a);
	free_stack(a);
	return (0);
}
