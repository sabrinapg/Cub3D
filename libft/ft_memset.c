/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:43:32 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 21:49:19 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			j;
	unsigned char	*q;

	j = 0;
	q = (unsigned char *)s;
	while (j < n)
	{
		q[j] = (unsigned char)c;
		j++;
	}
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	int	i = 0;
	char buffer[10];

//	memset(buffer, 0, sizeof(buffer));
	ft_memset(buffer, 0, sizeof(buffer));

	while (i < 10)
	{
		printf("%d ", buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
