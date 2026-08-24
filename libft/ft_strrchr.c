/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:44:22 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 21:44:33 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}

/*
#include <stdio.h>

int main(void)
{
	const char *str = "Hello, 42 Network!";
	int c = 'o';
	char *result = ft_strrchr(str, c);
	
	if (result)
		printf("Last occurrence of '%c': \"%s\"\n", c, result);
	else
		printf("Character '%c' not found in string.\n", c);
	
	c = '\0';
	result = ft_strrchr(str, c);
	
	if (result)
		printf("Searching for '\\0': \"%s\"\n", result);
	else
		printf("Null terminator not found (should never happen).\n");

	c = 'x';
	result = ft_strrchr(str, c);
	if (result)
		printf("Unexpected match for '%c': \"%s\"\n", c, result);
	else
		printf("Correctly found no match for '%c'.\n", c);
	return (0);
}
*/
