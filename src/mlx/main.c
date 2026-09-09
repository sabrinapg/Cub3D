#include "../includes/cub3d.h"
#include "../includes/parser.h"
#include "../includes/utils.h"
#include "../includes/validation.h"
#include "../includes/raycast.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_scene(&game.scene);
	if (argc != 2)
		return (print_error("usage: ./cub3D <map.cub>"));
	if (!parse_scene(argv[1], &game.scene))
	{
		free_scene(&game.scene);
		return (1);
	}
	if (!validate_scene(&game.scene))
	{
		free_scene(&game.scene);
		return (1);
	}
	init_player_from_map(&game);
	init_game(&game);
	init_textures(&game); // new function
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press_hook, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_hook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	free_scene(&game.scene);
	return (0);
}