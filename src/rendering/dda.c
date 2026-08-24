// the dir vector points to where the player is facing
// the plane vector defines field of view
// its length relative to dir sets the FOV.
// Typically 66 degrees, plane length circa 0.66 if dir = 1 (length)


// DDA Loop
//
// For each screen column x from 0 to WIDTH
// Convert x to camera space: camera_x = 2 * x / WIDTH - 1 (ranges -1 to 1)
//
// Ray direction: ray_dir_x = dir_x + plane_x * camera_x (vice versa for y)
// Figure out which grid cell you"re in and step cell-by-cell (not pixel by pixel) until hit a wall which is "1" in map
// Track whether crossed vertical/horizontal grid line - tells which wall tetexture NSEW to use


// Fisheye Fix
// Use the perpendicular distance to the tall (not raw Euclidean distance from player to hit point) or get warped/buldging view.


// Wall height
// line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
//
// Then draw that column centr


#include "cub3d.h"

void	init_dda(t_game *game, t_ray *ray)
{
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);

	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	run_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(game, ray->map_x, ray->map_y))
			hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}