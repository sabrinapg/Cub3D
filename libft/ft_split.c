/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:07:24 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 16:59:02 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **result, int idx)
{
	int	k;

	k = 0;
	while (k < idx)
	{
		free(result[k]);
		k++;
	}
	free(result);
}

static char	**fill_words(char **result, const char *s, char c)
{
	int	start;
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[idx] = ft_substr(s, start, i - start);
			if (!result[idx])
				return (free_split(result, idx), NULL);
			idx++;
		}
	}
	return (result[idx] = NULL, result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		word;

	if (!s)
		return (NULL);
	word = wordcount(s, c);
	result = malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (NULL);
	return (fill_words(result, s, c));
}
/*
#include <stdio.h>
int	main(void)
{
	char **a = ft_split("hello world test", "");
		printf("%s\n", a);

	char **b = ft_split("apple,banana,orange", ",");
		printf("%s\n", b);

	// Double delimiter means "a", "", ""....
	char **c = ft_split("a,,b,,c", ",");
		printf("%s\n", c);

	char **d = ft_split("nodelimiterhere", ",");
		printf("%s\n", d);

	// Returns null :)
	char **e = ft_split("", "");
		printf("%s", e);

	char **f = ft_split("x", ",");
		printf("%s", f);

	return (0);
}
*/
