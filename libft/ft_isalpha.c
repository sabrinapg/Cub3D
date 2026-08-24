/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:31:16 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/05/27 16:41:15 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!((c >= 65 && c <= 90) 
			|| (c >= 97 && c <= 122)))
		return (0);
	return (1);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char error[] = "Not an alphabet";
	char success[] = "It works!";
	int	c = '1';
	int	x = isalpha(c);
	int	y = ft_isalpha(c);

	printf("Original boolean value of isalpha(): %d\n", x);
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
