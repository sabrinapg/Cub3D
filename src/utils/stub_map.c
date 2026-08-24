#include "cub3d.h"



// hard coded test map
// 0 = empty
// 1 = wall
// stub_map.c — temporary, delete/replace once partner's parser is ready
#include "cub3d.h"

/*
** Hardcoded test map — 0 = empty, 1 = wall.
** Must be enclosed by walls (a real parser would validate this,
** but since this is a stub, just make sure YOU keep it enclosed
** or your DDA loop can walk off the array and segfault).
*/

void	stub_init_game(t_game *game)
{
	static char	*map[] = {
		"1111111111",
		"1000000001",
		"1000110001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1111111111",
		NULL
	};

	game->map = map;
	game->map_w = 10;
	game->map_h = 7;

	// Player starting position — pick a cell that's '0' (open space)
	game->player.pos_x = 2.5;
	game->player.pos_y = 2.5;

	// Facing direction (normalized-ish vector). This example faces east.
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;

	// Camera plane — perpendicular to dir, length sets FOV (~66 deg here)
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;

	// Movement/rotation speed constants, handy to have on the struct
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.03;
}

/*
** Quick sanity-check helper: is (x, y) a wall cell?
** Your real DDA loop will call something like this on game->map,
** but works identically whether the map came from the stub or
** your partner's parser, as long as the struct shape matches.
*/
int	is_wall(t_game *game, int map_x, int map_y)
{
	if (map_y < 0 || map_y >= game->map_h)
		return (1);
	if (map_x < 0 || map_x >= game->map_w)
		return (1);
	return (game->map[map_y][map_x] == '1');
}