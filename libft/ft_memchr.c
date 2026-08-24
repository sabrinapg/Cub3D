/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:46:14 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 21:46:27 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*j;
	unsigned char		find;
	size_t				i;

	j = (const unsigned char *)s;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (j[i] == find)
			return ((void *)(j + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
   char s[] = "Sabrina";
   char *result = ft_memchr(s, 'i', 7);
   
   if (result)
       printf("Found: %s\n", result);
   else
       printf("Not found\n");
   
   return (0);
}
*/
