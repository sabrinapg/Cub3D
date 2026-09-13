/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 23:14:10 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/14 00:55:55 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

static void	draw_minimap_cell(t_img *img, t_point p, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < MINIMAP_CELL)
	{
		dx = 0;
		while (dx < MINIMAP_CELL)
		{
			put_pixel(img, p.x + dx, p.y + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	draw_minimap_grid(t_game *game, t_map *map)
{
	int		x;
	int		y;
	int		color;
	t_point	pt;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == MAP_WALL)
				color = 0xFFFFFF;
			else
				color = 0x333333;
			pt.x = MINIMAP_MARGIN + x * MINIMAP_CELL;
			pt.y = MINIMAP_MARGIN + y * MINIMAP_CELL;
			draw_minimap_cell(&game->screen, pt, color);
			x++;
		}
		y++;
	}
}

static void	draw_player_marker(t_game *game, int cx, int cy)
{
	int	dx;
	int	dy;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			put_pixel(&game->screen, cx + dx, cy + dy, 0xFF0000);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	draw_minimap_grid(game, &game->scene.map);
	draw_player_marker(game,
		MINIMAP_MARGIN + (int)(game->scene.player.pos.x * MINIMAP_CELL),
		MINIMAP_MARGIN + (int)(game->scene.player.pos.y * MINIMAP_CELL));
}
