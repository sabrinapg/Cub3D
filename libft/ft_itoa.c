/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:10:07 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/06/04 18:10:58 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*handle_min_int(void)
{
	char	*str;
	char	*min_int;
	int		i;

	min_int = "-2147483648";
	str = malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	i = 0;
	while (min_int[i])
	{
		str[i] = min_int[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	fill_string(char *result, long num, int len)
{
	len--;
	while (len >= 0)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		is_negative;
	long	num;

	if (n == -2147483648)
		return (handle_min_int());
	len = count_digits(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	is_negative = (n < 0);
	if (n < 0)
		num = -(long)n;
	else
		num = n;
	fill_string(result, num, len);
	if (is_negative)
		result[0] = '-';
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	char *result;
   
	result = ft_itoa(42);
	printf("%s\n", result);
	free(result);
   
	result = ft_itoa(-42);
	printf("%s\n", result);
	free(result);
   
	result = ft_itoa(-2147483648);
	printf("%s\n", result);
	free(result);
	return (0);
}*/
