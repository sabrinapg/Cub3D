#include "../../includes/raycast.h"
#include "../../includes/utils.h"

static int	g_keys[65536];

int	close_hook(t_game *game)
{
	cleanup_game(game);
	free_scene(&game->scene);
	exit(0);
	return (0);
}

int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_hook(game);
	if (keycode >= 0 && keycode < 65536)
		g_keys[keycode] = 1;
	return (0);
}

int	key_release_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode >= 0 && keycode < 65536)
		g_keys[keycode] = 0;
	return (0);
}

void	handle_input(t_game *game)
{
	double	move_x;
	double	move_y;
	t_vec	*dir;

	dir = &game->scene.player.dir;
	move_x = 0;
	move_y = 0;
	if (g_keys[KEY_W])
	{
		move_x += dir->x * MOVE_SPEED;
		move_y += dir->y * MOVE_SPEED;
	}
	if (g_keys[KEY_S])
	{
		move_x -= dir->x * MOVE_SPEED;
		move_y -= dir->y * MOVE_SPEED;
	}
	if (g_keys[KEY_A])
	{
		move_x += dir->y * MOVE_SPEED;
		move_y -= dir->x * MOVE_SPEED;
	}
	if (g_keys[KEY_D])
	{
		move_x -= dir->y * MOVE_SPEED;
		move_y += dir->x * MOVE_SPEED;
	}
	if (move_x != 0 || move_y != 0)
		move_player(game, move_x, move_y);
	if (g_keys[KEY_LEFT])
		rotate_player(game, -ROT_SPEED);
	if (g_keys[KEY_RIGHT])
		rotate_player(game, ROT_SPEED);
}