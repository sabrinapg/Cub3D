/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:42:16 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/14 00:50:57 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "mlx.h"
# include <math.h>

# define PLAYER_RADIUS 0.2
# define MOVE_SPEED 0.03
# define ROT_SPEED 0.03
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define MINIMAP_CELL 3
# define MINIMAP_MARGIN 10

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

// for main
void	init_game(t_game *game);
void	cleanup_game(t_game *game);
void	init_player_from_map(t_game *game);
int		render_frame(t_game *game);
int		key_press_hook(int keycode, t_game *game);
int		key_release_hook(int keycode, t_game *game);
int		close_hook(t_game *game);
void	handle_input(t_game *game);

// for rendering
void	setup_ray(t_game *game, t_ray *ray, int x);
void	init_dda(t_game *game, t_ray *ray);
void	run_dda(t_game *game, t_ray *ray);
void	calc_wall_height(t_ray *ray);
void	draw_column(t_game *game, t_ray *ray, int x);
void	put_pixel(t_img *img, int x, int y, int color);
int		is_wall(t_game *game, int map_x, int map_y);

// my movement side
void	move_player(t_game *game, double move_x, double move_y);
void	rotate_player(t_game *game, double angle);

void	init_textures(t_game *game);
t_img	*pick_texture(t_game *game, t_ray *ray);
int		sample_texture(t_img *tex, int tex_x, int tex_y);
t_img	*get_tex_column(t_game *game, t_ray *ray, int *tex_x);
void	draw_minimap(t_game *game);

#endif
