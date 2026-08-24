#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		exit(1);
	game->screen.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bpp,
			&game->screen.line_len,
			&game->screen.endian);
}

void	cleanup_game(t_game *game)
{
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	init_game(&game);
	stub_init_game(&game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_hook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}