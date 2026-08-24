/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:46:02 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/03 15:48:49 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = 0;
	s = ft_strlen(src);
	i = 0;
	while (dest[d] && d < n)
		d++;
	if (d == n)
		return (n + s);
	while ((src[i] && (d + i < n - 1)))
	{
		dest[d + i] = src[i];
		i++;
	}
	if (d + i < n)
		dest[d + i] = '\0';
	return (d + s);
}
/*
// compile with -lbsd flag
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	a[] = "Meow";
	char	b[] = "A cat says: ";
	unsigned int m = 2;

	unsigned int	cut = strlcat(a, b, m);

	printf("Length of the real concat: %u\n", cut);
	
	char	c[] = "Meow";
	char	d[] = "A cat says: ";
	unsigned int	scissors = ft_strlcat(c, d, m);
	printf("Length of the mimicked concat: %u\n", scissors);
	return (0);
}
*/
