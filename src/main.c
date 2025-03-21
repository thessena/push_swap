/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:38 by thessena          #+#    #+#             */
/*   Updated: 2025/03/21 19:15:51 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	convert_to_digits(int n, char *num, int *i)
{
	*i = 0;
	if (n == 0)
	{
		num[*i] = '0';
		(*i)++;
	}
	while (n > 0)
	{
		num[*i] = (n % 10) + '0';
		(*i)++;
		n = n / 10;
	}
}

void	print_stack(t_stack *stack)
{
	int		i;
	int		n;
	char	num[12];

	while (stack)
	{
		n = stack->value;
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		convert_to_digits(n, num, &i);
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
	a = init_stack(argc, argv);
	b = NULL;
	// write(1, "Vor Sortierung:\n", 16);
	// print_stack(a);
	turk_sort(&a, &b);
	// write(1, "Nach Sortierung:\n", 17);
	// print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
