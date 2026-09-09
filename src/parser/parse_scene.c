/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:34:00 by makassa           #+#    #+#             */
/*   Updated: 2026/08/26 11:34:00 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"
#include <fcntl.h>

static int	has_cub_extension(char *path)
{
	size_t	len;
	size_t	ext_len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	ext_len = ft_strlen(EXT_CUB);
	if (len <= ext_len)
		return (0);
	if (ft_strncmp(path + len - ext_len, EXT_CUB, ext_len + 1) != 0)
		return (0);
	return (1);
}

static int	fail_read_scene(int fd, char **lines, char *line)
{
	if (fd >= 0)
		close(fd);
	free(line);
	free_split(lines);
	return (print_error("scene file could not be loaded"), 0);
}

static int	read_file_lines(int fd, char ***lines, char **line)
{
	char	buffer;
	int		index;
	int		bytes;

	index = 0;
	bytes = read(fd, &buffer, 1);
	while (bytes > 0)
	{
		if (buffer == '\n' && !store_line(lines, line, &index))
			return (fail_read_scene(fd, *lines, *line));
		if (buffer != '\n' && !append_char(line, buffer))
			return (fail_read_scene(fd, *lines, *line));
		bytes = read(fd, &buffer, 1);
	}
	if (bytes < 0)
		return (fail_read_scene(fd, *lines, *line));
	if (*line && !store_line(lines, line, &index))
		return (fail_read_scene(fd, *lines, *line));
	return (1);
}

int	read_scene_file(char *path, char ***lines)
{
	char	*line;
	int		fd;
	int		count;

	count = count_file_lines(path);
	*lines = alloc_file_lines(count);
	if (count <= 0 || !*lines)
		return (print_error("scene file could not be loaded"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fail_read_scene(fd, *lines, NULL));
	line = NULL;
	if (!read_file_lines(fd, lines, &line))
		return (0);
	close(fd);
	return (1);
}

int	parse_scene(char *path, t_scene *scene)
{
	char	**lines;
	int		map_start;

	lines = NULL;
	map_start = -1;
	if (!has_cub_extension(path))
		return (print_error("scene file must use .cub extension"), 0);
	if (!read_scene_file(path, &lines))
		return (0);
	if (!parse_config_lines(lines, scene, &map_start))
	{
		free_split(lines);
		return (0);
	}
	if (!parse_map(lines, map_start, scene))
	{
		free_split(lines);
		return (0);
	}
	free_split(lines);
	return (1);
}
