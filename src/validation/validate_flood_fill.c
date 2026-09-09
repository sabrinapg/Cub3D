/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flood_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:06:48 by makassa           #+#    #+#             */
/*   Updated: 2026/09/09 08:06:51 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/validation.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"

static int	find_player_position(t_map *map, int *x, int *y)
{
	*y = 0;
	while (*y < map->height)
	{
		*x = 0;
		while (map->grid[*y][*x])
		{
			if (map->grid[*y][*x] == PLAYER_N)
				return (1);
			if (map->grid[*y][*x] == PLAYER_S)
				return (1);
			if (map->grid[*y][*x] == PLAYER_E)
				return (1);
			if (map->grid[*y][*x] == PLAYER_W)
				return (1);
			*x = *x + 1;
		}
		*y = *y + 1;
	}
	return (0);
}

char	**duplicate_map_grid(t_map *map)
{
	char	**grid;
	int		index;

	grid = malloc(sizeof(char *) * (map->height + 1));
	if (!grid)
		return (NULL);
	index = 0;
	while (index < map->height)
	{
		grid[index] = ft_strdup(map->grid[index]);
		if (!grid[index])
		{
			grid[index] = NULL;
			free_split(grid);
			return (NULL);
		}
		index++;
	}
	grid[index] = NULL;
	return (grid);
}

static int	flood_fill_map(char **grid, int x, int y)
{
	if (y < 0 || !grid[y] || x < 0)
		return (0);
	if (x >= (int)ft_strlen(grid[y]))
		return (0);
	if (grid[y][x] == MAP_SPACE)
		return (0);
	if (grid[y][x] == MAP_WALL || grid[y][x] == 'V')
		return (1);
	grid[y][x] = 'V';
	if (!flood_fill_map(grid, x + 1, y))
		return (0);
	if (!flood_fill_map(grid, x - 1, y))
		return (0);
	if (!flood_fill_map(grid, x, y + 1))
		return (0);
	if (!flood_fill_map(grid, x, y - 1))
		return (0);
	return (1);
}

int	validate_map_closed(t_map *map)
{
	char	**grid;
	int		x;
	int		y;
	int		closed;

	if (!find_player_position(map, &x, &y))
		return (print_error("missing player"), 0);
	grid = duplicate_map_grid(map);
	if (!grid)
		return (print_error("memory allocation failed"), 0);
	closed = flood_fill_map(grid, x, y);
	free_split(grid);
	if (!closed)
		return (print_error("map is not closed"), 0);
	return (1);
}
