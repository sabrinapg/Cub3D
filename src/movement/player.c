#include "raycast.h"

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

void	init_player_from_map(t_game *game)
{
	t_map		*map;
	t_player	*player;
	int			x;
	int			y;
	char		c;

	map = &game->scene.map;
	player = &game->scene.player;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			c = map->grid[y][x];
			if (c == PLAYER_N || c == PLAYER_S
				|| c == PLAYER_E || c == PLAYER_W)
			{
				player->orientation = c;
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				set_player_direction(player, c);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	t_player	*player;
	int			new_map_x;
	int			new_map_y;

	player = &game->scene.player;
	new_map_x = (int)(player->pos.x + move_x);
	new_map_y = (int)(player->pos.y + move_y);
	if (!is_wall(game, new_map_x, (int)player->pos.y))
		player->pos.x += move_x;
	if (!is_wall(game, (int)player->pos.x, new_map_y))
		player->pos.y += move_y;
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