/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 02:21:54 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:28:58 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/raycast.h"
#include "../../includes/utils.h"

static void	set_player_direction(t_player *player, char c)
{
	if (c == PLAYER_N)
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (c == PLAYER_S)
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (c == PLAYER_E)
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	player->plane.x = player->dir.y * FOV;
	player->plane.y = -player->dir.x * FOV;
}

static int	find_player_in_row(t_player *player, char *row, int y)
{
	int		x;
	char	c;

	x = 0;
	while (row[x])
	{
		c = row[x];
		if (c == PLAYER_N || c == PLAYER_S
			|| c == PLAYER_E || c == PLAYER_W)
		{
			player->orientation = c;
			player->pos.x = x + 0.5;
			player->pos.y = y + 0.5;
			set_player_direction(player, c);
			return (1);
		}
		x++;
	}
	return (0);
}

void	init_player_from_map(t_game *game)
{
	t_map		*map;
	t_player	*player;
	int			y;

	map = &game->scene.map;
	player = &game->scene.player;
	y = 0;
	while (y < map->height)
	{
		if (find_player_in_row(player, map->grid[y], y))
			return ;
		y++;
	}
}

void	rotate_player(t_game *game, double angle)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &game->scene.player;
	old_dir_x = player->dir.x;
	player->dir.x = old_dir_x * cos(angle) - player->dir.y * sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y * cos(angle);
	old_plane_x = player->plane.x;
	player->plane.x = old_plane_x * cos(angle) - player->plane.y * sin(angle);
	player->plane.y = old_plane_x * sin(angle) + player->plane.y * cos(angle);
}
