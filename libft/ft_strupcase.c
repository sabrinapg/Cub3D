/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:28:29 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/02/26 17:44:21 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	s;

	s = 0;
	if (!str)
		return (str);
	while (str[s] != '\0')
	{
		if ((str[s] >= 'a' && str[s] <= 'z'))
			str[s] -= 32;
		s++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char error[] = "Hahaha sucker";
	char S[] = "ABCDEFG";
	char s[] = "abcdefg";
	char n[] = "";

	if (*s != '\0')
	{
		printf("%s", ft_strupcase(s));
	}
	else
		printf("%s", error);
	return (0);
}i
*/
