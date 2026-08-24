#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
// # include "libft.h"

// For window and rendering constraints
# define WIN_WIDTH   1280
# define WIN_HEIGHT  720
# define TILE_SIZE   64
# define FOV         0.66  // camera plane length ~66 degrees

// Key Codes
# define KEY_W       119
# define KEY_A       97
# define KEY_S       115
# define KEY_D       100
# define KEY_LEFT    65361
# define KEY_RIGHT   65363
# define KEY_ESC     65307

// Manage playaa
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;


// DDA Per Ray
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
	int		side;        // 0 = x-side hit (E/W wall), 1 = y-side hit (N/S wall)
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;


// IMG Buffer WRAPPER (direkt pixel writes)
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// Main gam state
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_player	player;
	char		**map;       // owned by parser (or stub)
	int			map_w;
	int			map_h;

	// texture image handles - to be filled later
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
}	t_game;




/* ---------- main.c ---------- */
int		main(int argc, char **argv);
void	init_game(t_game *game);
void	cleanup_game(t_game *game);


/* ---------- stub_map.c (temporary) --- */
void	stub_init_game(t_game *game);
int		is_wall(t_game *game, int map_x, int map_y);


/* ---------- raycast.c ---------- */
void	setup_ray(t_game *game, t_ray *ray, int x);


/* ---------- dda.c ---------- */
void	init_dda(t_game *game, t_ray *ray);
void	run_dda(t_game *game, t_ray *ray);


/* ---------- raycast.c ---------- */
void	calc_wall_height(t_ray *ray);


/* ---------- render.c ---------- */
void	draw_column(t_game *game, t_ray *ray, int x);
void	put_pixel(t_img *img, int x, int y, int color);


/* ---------- player.c ---------- */
void	move_player(t_game *game, double move_x, double move_y);
void	rotate_player(t_game *game, double angle);


/* ---------- hooks.c ---------- */
int		render_frame(t_game *game);
int		key_hook(int keycode, t_game *game);
int		close_hook(t_game *game);

#endif