/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:48:16 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/02/26 17:47:10 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 'a';
	int b = 'B';
	int j = ft_tolower(a);
	int k = ft_tolower(b);

	printf("a = %d\n", j);
	printf("b = %d", k);
	return (0);
}
*/
