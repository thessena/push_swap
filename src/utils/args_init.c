/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:41:08 by thessena          #+#    #+#             */
/*   Updated: 2025/03/27 19:21:48 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static int	fill_split_array(char **result, char *arg, int words)
{
	int	i;
	int	start;
	int	word_idx;

	i = 0;
	word_idx = 0;
	while (arg[i] && word_idx < words)
	{
		while (is_space(arg[i]))
			i++;
		if (arg[i])
		{
                        start = i;
                        while (arg[i] && !is_space(arg[i]))
                                i++;
                        result[word_idx] = extract_word(arg, start, i);
                        if (!result[word_idx])
                        {
                                result[word_idx] = NULL;
                                return (0);
                        }
                        word_idx++;
                }
        }
        result[word_idx] = NULL;
        return (1);
}

char	**split_args(char *arg, int *count)
{
	char	**result;
	int		words;

	if (!arg || !count)
		return (NULL);
	words = count_words(arg);
	if (words == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!fill_split_array(result, arg, words))
	{
		free_split(result);
		return (NULL);
	}
	*count = words;
	return (result);
}


