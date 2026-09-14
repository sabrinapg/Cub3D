/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:48:49 by makassa           #+#    #+#             */
/*   Updated: 2026/08/24 16:50:44 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/parser.h"
#include "../includes/utils.h"
#include "../includes/validation.h"
#include "../includes/raycast.h"

int	args_validate(int argc, char **argv, t_game *game)
{
	init_scene(&game->scene);
	if (argc != 2)
	{
		print_error("usage: ./cub3D <map.cub>");
		return (0);
	}
	if (!parse_scene(argv[1], &game->scene))
	{
		free_scene(&game->scene);
		return (0);
	}
	if (!validate_scene(&game->scene))
	{
		free_scene(&game->scene);
		return (0);
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!args_validate(argc, argv, &game))
		return (1);
	init_player_from_map(&game);
	init_game(&game);
	init_textures(&game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press_hook, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_hook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	free_scene(&game.scene);
	return (0);
}
*/
