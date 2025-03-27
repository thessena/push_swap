/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:23:58 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 19:14:07 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_and_append(t_stack **stack, long num, char *str)
{
	if (!is_valid_number(str) || num > INT_MAX || num < INT_MIN || has_duplicate(*stack, num))
	{
		free_stack(*stack);
		write(2, "Error\n", 6);
		return (0);
	}
	append_node(stack, (int)num);
	if (!*stack)
	{
		free_stack(*stack);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

t_stack	*handle_single_arg(char *arg)
{
	t_stack	*a;
	char	**numbers;
	int		count;
	int		i;

	a = NULL;
	numbers = split_args(arg, &count);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		if (!check_and_append(&a, ft_atol(numbers[i]), numbers[i]))
		{
			free_split(numbers);
			return (NULL);
		}
		i++;
	}
	free_split(numbers);
	return (a);
}

t_stack	*handle_multi_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!check_and_append(&a, ft_atol(argv[i]), argv[i]))
			return (NULL);
		i++;
	}
	return (a);
}

t_stack	*init_stack(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (handle_single_arg(argv[1]));
	return (handle_multi_args(argc, argv));
}

void	set_list_index(t_stack *list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (list)
	{
		list->index = i;
		i++;
		list = list->next;
	}
}
