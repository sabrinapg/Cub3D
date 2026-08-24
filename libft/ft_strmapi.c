/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:13:08 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/04 18:13:29 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>
void	ft_up(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	ft_up3(unsigned int i, char *c)
{
	if (i % 3 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	ff_putchar(unsigned int i, char *c)
{
	write(1, &c, 1);
}

void	ff_id(unsigned int i, char *c)
{
	printf("%c == %u", *c, i);
}

int	main(void)
{
	char a[] = "hello world";
	char b[] = "Sabrina Pengiran";

	printf("Before: '%s'\n", a);
	ft_strmapi(a, ft_up);
//	ft_strmapi(a, ft_up3);
//	ft_strmapi(a, ff_putchar);
//	ft_strmapi(a, ff_id);
	printf("After:  '%s'\n", a);

	printf("\n");
	
	return (0);
}
*/
