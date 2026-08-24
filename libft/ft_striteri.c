/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:13:41 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/04 21:10:46 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
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
	ft_striteri(a, ft_up);
//	ft_striteri(a, ft_up3);
//	ft_striteri(a, ff_putchar);
//	ft_striteri(a, ff_id);
	printf("After:  '%s'\n", a);

	printf("\n");
	
	return (0);
}
*/
