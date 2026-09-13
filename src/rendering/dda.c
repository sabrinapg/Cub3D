/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:39:49 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 23:54:24 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_dda(t_game *game, t_ray *ray)
{
	t_vec	*pos;

	pos = &game->scene.player.pos;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - pos->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - pos->y) * ray->delta_dist_y;
	}
}

static void	calc_perp_dist(t_game *game, t_ray *ray)
{
	t_vec	*pos;

	pos = &game->scene.player.pos;
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - pos->x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
		ray->wall_x = pos->y + ray->perp_wall_dist * ray->ray_dir_y;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - pos->y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
		ray->wall_x = pos->x + ray->perp_wall_dist * ray->ray_dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
}

void	run_dda(t_game *game, t_ray *ray)
{
	t_vec	*pos;
	int		hit;

	pos = &game->scene.player.pos;
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
	calc_perp_dist(game, ray);
}
