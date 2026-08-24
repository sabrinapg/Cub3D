/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:49:22 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/05/27 18:52:46 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p++ = 0;
	}
}

/*
//#include <strings.h>
#include <stdio.h>
int	main(void)
{
	int i = 0;
	char a[20] = "Salami 42Berlin!!!";

	printf("Before bzero: %s\n", a);
	ft_bzero(a + 7, 6);
	printf("After bzero:  %s\n", a);

	while (i < 20)
	{
		printf("%d ", (unsigned char)a[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
