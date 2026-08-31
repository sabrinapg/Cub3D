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

int	parse_scene(char *path, t_scene *scene)
{
	char	**lines;
	int		map_start;

	lines = NULL;
	map_start = -1;
	if (!has_cub_extension(path))
		return (print_error("scene file must use .cub extension"));
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
