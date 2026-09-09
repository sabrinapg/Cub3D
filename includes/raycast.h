#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "mlx.h"
# include <math.h>

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

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

#endif