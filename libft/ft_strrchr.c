/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:38:40 by makassa           #+#    #+#             */
/*   Updated: 2025/06/12 17:39:10 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*s_end;

	i = 0;
	s_end = NULL;
	if ((unsigned char) c == '\0' && s)
	{
		s_end = s + ft_strlen(s);
		return ((char *)s_end);
	}
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			s_end = &s[i];
		i++;
	}
	return ((char *)s_end);
}
