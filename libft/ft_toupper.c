/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:47:12 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 21:47:25 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	int c = 'C';
	int d = 'd';
	int j = ft_toupper(c);
	int k = ft_toupper(d);

	printf("a = %d\n", j);
	printf("b = %d", k);
	return (0);
}
*/
