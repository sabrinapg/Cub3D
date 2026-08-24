#include "cub3d.h"

void	setup_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x
		+ game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y
		+ game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
}

int	render_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		setup_ray(game, &ray, x);
		init_dda(game, &ray);
		run_dda(game, &ray);
		calc_wall_height(&ray);
		draw_column(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}