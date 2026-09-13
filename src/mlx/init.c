/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:37:39 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:37:41 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"
#include "../../includes/cub3d.h"

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
	if (game->tex_n.img)
		mlx_destroy_image(game->mlx, game->tex_n.img);
	if (game->tex_s.img)
		mlx_destroy_image(game->mlx, game->tex_s.img);
	if (game->tex_e.img)
		mlx_destroy_image(game->mlx, game->tex_e.img);
	if (game->tex_w.img)
		mlx_destroy_image(game->mlx, game->tex_w.img);
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

static void	load_texture(t_game *game, t_img *tex, char *path)
{
	int	width;
	int	height;

	tex->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!tex->img)
		exit(1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->tex_n, game->scene.textures.north_path);
	load_texture(game, &game->tex_s, game->scene.textures.south_path);
	load_texture(game, &game->tex_e, game->scene.textures.east_path);
	load_texture(game, &game->tex_w, game->scene.textures.west_path);
}
