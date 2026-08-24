#include "cub3d.h"

int	close_hook(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

static void	handle_movement(t_game *game, int keycode)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (keycode == KEY_W)
	{
		move_x = game->player.dir_x * game->player.move_speed;
		move_y = game->player.dir_y * game->player.move_speed;
	}
	else if (keycode == KEY_S)
	{
		move_x = -game->player.dir_x * game->player.move_speed;
		move_y = -game->player.dir_y * game->player.move_speed;
	}
	else if (keycode == KEY_A)
	{
		move_x = game->player.dir_y * game->player.move_speed;
		move_y = -game->player.dir_x * game->player.move_speed;
	}
	else if (keycode == KEY_D)
	{
		move_x = -game->player.dir_y * game->player.move_speed;
		move_y = game->player.dir_x * game->player.move_speed;
	}
	move_player(game, move_x, move_y);
}

static void	handle_rotation(t_game *game, int keycode)
{
	if (keycode == KEY_LEFT)
		rotate_player(game, -game->player.rot_speed);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, game->player.rot_speed);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_hook(game);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		handle_movement(game, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		handle_rotation(game, keycode);
	return (0);
}