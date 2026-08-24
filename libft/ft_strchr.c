/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:48:15 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 21:48:27 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	const char *str = "Hello, 42 Network!";
	int c = 'o';
	char *result = ft_strchr(str, c);
	
	if (result)
		printf("First occurrence of '%c': \"%s\"\n", c, result);
	else
		printf("Character '%c' not found in string.\n", c);
	
	c = '\0';
	result = ft_strchr(str, c);
	
	if (result)
		printf("Searching for '\\0': \"%s\"\n", result);
	else
		printf("Null terminator not found (should never happen).\n");

	c = 'x';
	result = ft_strchr(str, c);
	if (result)
		printf("Unexpected match for '%c': \"%s\"\n", c, result);
	else
		printf("Correctly found no match for '%c'.\n", c);
	return (0);
}
*/
