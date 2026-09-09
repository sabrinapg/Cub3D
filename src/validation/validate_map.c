/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:07:03 by makassa           #+#    #+#             */
/*   Updated: 2026/09/09 08:07:46 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/validation.h"
#include "../../includes/utils.h"

static int	is_valid_map_char(char character)
{
	if (character == MAP_WALL || character == MAP_EMPTY)
		return (1);
	if (character == MAP_SPACE || character == PLAYER_N)
		return (1);
	if (character == PLAYER_S || character == PLAYER_E)
		return (1);
	if (character == PLAYER_W)
		return (1);
	return (0);
}

int	validate_no_empty_map_lines(t_map *map)
{
	int	index;

	index = 0;
	while (index < map->height)
	{
		if (!map->grid[index])
			return (print_error("missing map row"), 0);
		if (is_empty_line(map->grid[index]))
			return (print_error("empty line in map"), 0);
		index++;
	}
	return (1);
}

int	validate_map_chars(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (!map->grid[y])
			return (print_error("missing map row"), 0);
		x = 0;
		while (map->grid[y][x])
		{
			if (!is_valid_map_char(map->grid[y][x]))
				return (print_error("invalid map character"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_player_count(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		if (!map->grid[y])
			return (print_error("missing map row"), 0);
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == PLAYER_N || map->grid[y][x] == PLAYER_S)
				count++;
			if (map->grid[y][x] == PLAYER_E || map->grid[y][x] == PLAYER_W)
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (print_error("map must contain one player"), 0);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!map || !map->grid || map->height <= 0 || map->width <= 0)
		return (print_error("missing map"), 0);
	if (!validate_no_empty_map_lines(map))
		return (0);
	if (!validate_map_chars(map))
		return (0);
	if (!validate_player_count(map))
		return (0);
	if (!validate_map_closed(map))
		return (0);
	return (1);
}
