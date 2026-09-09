/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:11:41 by makassa           #+#    #+#             */
/*   Updated: 2025/06/11 12:13:24 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	size_t	len;
	char	*rsrc;

	i = 0;
	len = ft_strlen(src);
	rsrc = (char *)malloc((len + 1) * sizeof(char));
	if (!rsrc)
		return (NULL);
	while (src[i])
	{
		rsrc[i] = src[i];
		i++;
	}
	rsrc[i] = '\0';
	return (rsrc);
}
