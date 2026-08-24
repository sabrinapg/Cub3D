#include "cub3d.h"

void	move_player(t_game *game, double move_x, double move_y)
{
	int	new_map_x;
	int	new_map_y;

	new_map_x = (int)(game->player.pos_x + move_x);
	new_map_y = (int)(game->player.pos_y + move_y);
	if (!is_wall(game, new_map_x, (int)game->player.pos_y))
		game->player.pos_x += move_x;
	if (!is_wall(game, (int)game->player.pos_x, new_map_y))
		game->player.pos_y += move_y;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = old_dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = old_plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}
