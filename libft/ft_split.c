/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 20:29:09 by makassa           #+#    #+#             */
/*   Updated: 2025/06/29 20:29:35 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freearr(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	ft_mallocarr(char ***ptr, char const *s, char c)
{
	size_t	i;
	int		nw;

	if (!s)
		return (-1);
	i = 0;
	nw = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			nw++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	*ptr = (char **)malloc(sizeof(char *) * (nw + 1));
	return (nw);
}

static int	ft_fillarr(char **res, char const *s, char c, size_t i)
{
	size_t	strlen;
	size_t	k;
	size_t	ind;

	strlen = 0;
	ind = i;
	while (s[ind] != c && s[ind])
	{
		ind++;
		strlen++;
	}
	*res = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!*res)
		return (-1);
	k = 0;
	while (k < strlen)
	{
		(*res)[k] = s[i];
		i++;
		k++;
	}
	(*res)[k] = '\0';
	return ((int)i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**ptr;
	size_t	i;
	int		tmp;

	tmp = ft_mallocarr(&res, s, c);
	if (tmp < 0 || !res)
		return ((char **) NULL);
	ptr = res;
	res[tmp] = (char *) NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tmp = ft_fillarr(ptr, s, c, i);
			if (tmp < 0)
				return (ft_freearr(res), (char **) NULL);
			i = (size_t)tmp;
			ptr++;
		}
		else
			i++;
	}
	return (res);
}
