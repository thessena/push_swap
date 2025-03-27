/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:05:34 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 16:14:04 by thessena         ###   ########.fr       */
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

int	is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (count);
}

char	*extract_word(char *str, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_args(char *arg, int *count)
{
	char	**result;
	int		i;
	int		start;
	int		words;

	i = 0;
	words = count_words(arg);
	if (words == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	*count = words;
	words = 0;
	while (arg[i])
	{
		while (is_space(arg[i]))
			i++;
		if (arg[i])
		{
			start = i;
			while (arg[i] && !is_space(arg[i]))
				i++;
			result[words] = extract_word(arg, start, i);
			if (!result[words])
			{
				while (words > 0)
					free(result[--words]);
				free(result);
				return (NULL);
			}
			words++;
		}
	}
	result[words] = NULL;
	return (result);
}

long	ft_atol(const char *str)
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

void	free_split(char **split)
{
	int	i;
	
	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	long	num;
	int		i;
	char	**numbers;
	int		count;

	a = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		numbers = split_args(argv[1], &count);
		if (!numbers)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		i = 0;
		while (i < count)
		{
			if (!is_valid_number(numbers[i]))
			{
				free_split(numbers);
				free_stack(a);
				write(2, "Error\n", 6);
				return (NULL);
			}
			num = ft_atol(numbers[i]);
			if (num > INT_MAX || num < INT_MIN || has_duplicate(a, num))
			{
				free_split(numbers);
				free_stack(a);
				write(2, "Error\n", 6);
				return (NULL);
			}
			append_node(&a, (int)num);
			if (!a)
			{
				free_split(numbers);
				free_stack(a);
				write(2, "Error\n", 6);
				return (NULL);
		
			}
			i++;
		}
		free_split(numbers);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!is_valid_number(argv[i]))
			{
				free_stack(a);
				write(2, "Error\n", 6);
				return (NULL);
			}
			num = ft_atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN || has_duplicate(a, num))
			{
				free_stack(a);
				write(2, "Error\n", 6);
				return (NULL);
			}
			append_node(&a, (int)num);
			if (!a)
			{
				free_stack(a);
				write(2, "Error\n", 6);
				return (NULL);
			}
			i++;
		}
	}
	return (a);
}

void	set_list_index(t_stack *list)
{
	int	i;

	if (!list)
		return;
	i = 0;
	while (list)
	{
		list->index = i;
		i++;
		list = list->next;
	}
}
