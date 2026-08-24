/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:21:27 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/03/02 21:32:52 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	if (size == 0)
		return (l);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (l);
}

/*
// to cc use -lbsd flag
#include <stdio.h>
#ifdef __linux__
    #include <bsd/string.h>
#else
    #include <string.h>
#endif

int	main(void)
{
	char	ft_dest[50];
	char	real_dest[50];
	char	*src = "Meowwwwwww";
	unsigned int	size = 4;
	unsigned int	ft_result;
	unsigned int	real_result;

	printf("Original: \"%s\"\n", src);

	ft_result = ft_strlcpy(ft_dest, src, size);
	printf("ft_strlcpy Result: \"%s\" (Original Length: %u)\n", ft_dest, ft_result);

	real_result = strlcpy(real_dest, src, size);
	printf("strlcpy Result: \"%s\" Original Length: %u)\n", real_dest, real_result);
	return (0);
}
*/
