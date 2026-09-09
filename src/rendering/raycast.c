#include "raycast.h"

void	setup_ray(t_game *game, t_ray *ray, int x)
{
	t_player	*player;

	player = &game->scene.player;
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = player->dir.x + player->plane.x * ray->camera_x;
	ray->ray_dir_y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
}

int	render_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	handle_input(game);
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