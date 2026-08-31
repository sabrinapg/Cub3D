/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:20:37 by makassa           #+#    #+#             */
/*   Updated: 2026/08/31 16:21:27 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_isspace_cub(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}


int		is_empty_line(char *line)
{
	int	index;

	if (!line)
		return (1);
	index = 0;
	while (line[index])
	{
		if (!ft_isspace_cub(line[index]))
			return (0);
		index++;
	}
	return (1);
}

char	*trim_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
	{
		line[len - 1] = '\0';
		len--;
	}
	return (line);
}

int		has_only_spaces(char *line)
{
	return (is_empty_line(line));
}
