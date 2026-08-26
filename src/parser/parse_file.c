/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:34:00 by makassa           #+#    #+#             */
/*   Updated: 2026/08/26 11:34:00 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/libft.h"
//#include "../../includes/utils.h"
#include <fcntl.h>

int	count_file_lines(char *path)
{
	char	buffer;
	int		fd;
	int		count;
	int		has_chars;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	has_chars = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		has_chars = 1;
		if (buffer == '\n')
		{
			count++;
			has_chars = 0;
		}
	}
	close(fd);
	if (has_chars)
		count++;
	return (count);
}

char	**alloc_file_lines(int line_count)
{
	char	**lines;
	int		index;

	if (line_count <= 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	index = 0;
	while (index <= line_count)
	{
		lines[index] = NULL;
		index++;
	}
	return (lines);
}

static int	append_char(char **line, char character)
{
	char	*new_line;
	size_t	len;
	size_t	index;

	len = 0;
	if (*line)
		len = ft_strlen(*line);
	new_line = malloc(sizeof(char) * (len + 2));
	if (!new_line)
		return (0);
	index = 0;
	while (index < len)
	{
		new_line[index] = (*line)[index];
		index++;
	}
	new_line[index++] = character;
	new_line[index] = '\0';
	free(*line);
	*line = new_line;
	return (1);
}

static int	store_line(char ***lines, char **line, int *index)
{
	if (!*line)
	{
		*line = malloc(sizeof(char));
		if (!*line)
			return (0);
		(*line)[0] = '\0';
	}
	(*lines)[*index] = *line;
	*line = NULL;
	*index = *index + 1;
	return (1);
}

int	read_scene_file(char *path, char ***lines)
{
	char	buffer;
	char	*line;
	int		fd;
	int		index;
	int		count;

	count = count_file_lines(path);
	*lines = alloc_file_lines(count);
	if (count <= 0 || !*lines)
		return (print_error("scene file could not be loaded"));
	fd = open(path, O_RDONLY);
	line = NULL;
	index = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n' && !store_line(lines, &line, &index))
			return (0);
		if (buffer != '\n' && !append_char(&line, buffer))
			return (0);
	}
	close(fd);
	if (line && !store_line(lines, &line, &index))
		return (0);
	return (1);
}
