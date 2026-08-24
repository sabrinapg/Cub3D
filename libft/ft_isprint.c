/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:35:36 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/05/27 17:04:08 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int	c = '\t';
	int	d = '\t';
	int	p = isprint(c);
	int	fp = ft_isprint(d);

	if (p == 0)
		printf("Control: Not Printable - %d\n", p);
	else
		printf("Control: Printable - %d\n", fp);
	if (fp == 0)
		printf("Mimic: Not Printable - %d", fp);
	else
		printf("Mimic: Printable = %d", fp);
}
*/
