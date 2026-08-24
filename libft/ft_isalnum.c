/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:39:00 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/05/27 17:20:25 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
		|| (c >= 48 && c <= 57));
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char error[] = "Not a number or an alphabet";
	char success[] = "It works!";
	int	c = 'a';
	int	x = isalnum(c);
	int	y = ft_isalnum(c);

	if (x == 0)
		printf("%s\n", error);
	else
		printf("%s\n", success);

	if (y == 0)
		printf("%s", error);
	else
		printf("%s", success);
	return (0);
}
*/
