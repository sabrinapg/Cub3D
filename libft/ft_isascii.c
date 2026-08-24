/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:42:06 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/03 15:47:08 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int c = 1;
	int d = 127;
	int e = 'a';

	int m = isascii(c);
	int n = isascii(d);
	int o = isascii(e);

	int j = ft_isascii(c);
	int k =	ft_isascii(d);
	int l =	ft_isascii(e);

	printf("Control %d %d %d\n", m, n, o);
	printf("Mimic: %d %d %d\n", j, k, l);
	return (0);
}
*/
