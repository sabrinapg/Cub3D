/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:47:48 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/04 21:35:15 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle;
	size_t	h1;
	size_t	n1;

	needle = ft_strlen(little);
	h1 = 0;
	if (needle == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[h1] && h1 < len)
	{
		if (h1 + needle > len)
			break ;
		n1 = 0;
		while (n1 < needle && big[h1 + n1] == little[n1])
			n1++;
		if (n1 == needle)
			return ((char *)(big + h1));
		h1++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	const char *s1 = "Sabrina";
	const char *s2 = "ina";
	char a* = ft_strnstr(s1, s2, 3);
	char b* = ft_strnstr(s1, s2, 7);
//	char a* = strnstr(s1, s2, 3);
//	char b* = strnstr(s1, s2, 7);

	const char *s3 = "12World" ;
	const char *s4 = "World" ;
	char c* = ft_strnstr(s3, s4, 3);
	char d* = ft_strnstr(s3, s4, 7);
//	char c* = strnstr(s3, s4, 3);
//	char d* = strnstr(s3, s4, 7);

	printf("This Fails: %s\n", a);
	printf("This Passes: %s\n", b);
	printf("This Fails: %s\n", c);
	printf("This Passes:%s\n", d);

	return (0);
}
*/