/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:28:00 by makassa           #+#    #+#             */
/*   Updated: 2025/06/29 19:28:12 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_mem;

	if (!nmemb || !size)
	{
		new_mem = (void *)malloc(1);
		if (!new_mem)
			return (NULL);
		ft_bzero(new_mem, 1);
		return (new_mem);
	}
	else if (nmemb > (size_t)-1 / size)
		return (NULL);
	new_mem = (void *)malloc(size * nmemb);
	if (!new_mem)
		return (NULL);
	ft_bzero(new_mem, size * nmemb);
	return (new_mem);
}
