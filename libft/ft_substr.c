/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:09:18 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/02 21:30:06 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dua;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dua = (char *)malloc(len + 1);
	if (!dua)
		return (NULL);
	while (i < len && s[start + i])
	{
		dua[i] = s[start + i];
		i++;
	}
	dua[i] = '\0';
	return (dua);
}

/*
int	main(void)
{
	char *result;
	char a[] = "Hello World, my name is Sabrina";
	int b = 4;
	int c = 10;

	result = ft_substr(a, b, c);
	if (result)
	{
		write(1, result, ft_strlen(result));
		write(1, "\n", 1);
		free(result);
	}
	return (0);
}
*/
