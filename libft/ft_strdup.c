/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:53:20 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/03 15:45:44 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	l;
	char	*copy;

	i = 0;
	l = ft_strlen(s);
	copy = (char *)malloc(l + 1);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	const char *src = "Sabrina";

	printf("Created: %s\n", ft_strdup(src));
	printf("Control: %s\n", strdup(src));
	
	return (0);
}
*/
