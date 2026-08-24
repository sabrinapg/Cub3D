/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:39:00 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/05/27 16:39:52 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char error[] = "Not a number";
	char success[] = "It works!";
	int	c = '2';
	int	x = isdigit(c);
	int	y = ft_isdigit(c);

	printf("Original boolean value of isdigit(): %d\n", x);
	if (y == 0)
	{
		printf("%s\n", error);
		printf("Mimic boolean value: %d", y);
	}
	else
	{
		printf("%s\n", success);
		printf("Mimic boolean value: %d", y);
	}
	return (0);
}
*/
