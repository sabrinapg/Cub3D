/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:41:14 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/04 21:49:46 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			mx;
	size_t			i;
	void			*bx;
	unsigned char	*byte_bx;

	i = 0;
	if (nmemb != 0 && size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	mx = nmemb * size;
	bx = malloc(mx);
	if (!bx)
		return (NULL);
	byte_bx = (unsigned char *)bx;
	while (i < mx)
	{
		byte_bx[i] = 0;
		i++;
	}
	return (bx);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	int *arr = (int *)ft_calloc(5, sizeof(int));
	int i = 0;
	if (arr)
	{
		while (i < 5)
		{
			printf("%d ", arr[i]);
			i++;
		}
        printf("\n");
        free(arr);
    }
    return (0);
}
*/
