/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:42:34 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:15:30 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	calc_wall_height(t_ray *ray)
{
	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	if (ray->line_height < 1)
		ray->line_height = 1;
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_img	*tex;
	int		tex_x;
	int		tex_y;
	int		y;
	double	tex_pos;

	tex = get_tex_column(game, ray, &tex_x);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(&game->screen, x, y++, game->scene.ceiling.value);
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* ((double)TEX_HEIGHT / ray->line_height);
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += (double)TEX_HEIGHT / ray->line_height;
		put_pixel(&game->screen, x, y++, sample_texture(tex, tex_x, tex_y));
	}
	while (y < WIN_HEIGHT)
		put_pixel(&game->screen, x, y++, game->scene.floor.value);
}
