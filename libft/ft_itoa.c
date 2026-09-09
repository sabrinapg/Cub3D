/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:59:16 by makassa           #+#    #+#             */
/*   Updated: 2025/06/24 16:33:04 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_getlen(long long n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_makestr(char *ptr, long long n, int sig)
{
	size_t	len;

	len = ft_getlen(n);
	if (sig < 0)
		len++;
	ptr[len--] = '\0';
	while (n >= 10)
	{
		ptr[len--] = n % 10 + 48;
		n = n / 10;
	}
	ptr[len] = n + 48;
	if (sig < 0)
		ptr[0] = '-';
	return ;
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			nbstr;
	int			sig;
	char		*res;

	if (n == 0)
		return (ft_strdup("0"));
	nb = (long long)n;
	sig = 1;
	if (nb < 0)
	{
		sig = -1;
		nb = -nb;
	}
	nbstr = ft_getlen(nb);
	if (sig < 0)
		nbstr++;
	res = (char *)malloc(sizeof(char) * (nbstr + 1));
	if (!res)
		return ((char *) NULL);
	ft_makestr(res, nb, sig);
	return (res);
}
