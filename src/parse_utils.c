/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:05:34 by thessena          #+#    #+#             */
/*   Updated: 2025/03/14 19:03:38 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

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
		i++;
	}
	return (sign * result);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	long	num;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN || has_duplicate(a, num))
		{
			free_stack(a);
			return (NULL);
		}
		append_node(&a, (int)num);
		if (!a)
		{
			free_stack(a);
			return (NULL);
		}
		i++;
	}
	return (a);
}
