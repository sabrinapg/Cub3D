/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:27:29 by makassa           #+#    #+#             */
/*   Updated: 2026/08/31 16:27:31 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"

static int	count_map_height(char **lines, int start)
{
	int	height;

	height = 0;
	while (lines[start + height])
		height++;
	return (height);
}

static int	get_map_width(char **lines, int start)
{
	int	width;
	int	line_width;
	int	index;

	width = 0;
	index = start;
	while (lines[index])
	{
		line_width = ft_strlen(lines[index]);
		if (line_width > width)
			width = line_width;
		index++;
	}
	return (width);
}

int	copy_map_lines(char **lines, int start, t_map *map)
{
	int	index;

	index = 0;
	while (index < map->height)
	{
		map->grid[index] = ft_strdup(lines[start + index]);
		if (!map->grid[index])
		{
			map->grid[index] = NULL;
			return (0);
		}
		index++;
	}
	map->grid[index] = NULL;
	return (1);
}

int	parse_map(char **lines, int start, t_scene *scene)
{
	if (!lines || start < 0 || !scene)
		return (print_error("missing map"));
	scene->map.height = count_map_height(lines, start);
	if (scene->map.height <= 0)
		return (print_error("missing map"));
	scene->map.width = get_map_width(lines, start);
	scene->map.grid = malloc(sizeof(char *) * (scene->map.height + 1));
	if (!scene->map.grid)
		return (print_error("memory allocation failed"));
	if (!copy_map_lines(lines, start, &scene->map))
	{
		free_split(scene->map.grid);
		scene->map.grid = NULL;
		return (print_error("memory allocation failed"));
	}
	return (1);
}
