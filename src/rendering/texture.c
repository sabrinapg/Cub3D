/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:42:34 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:15:13 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_img	*pick_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&game->tex_w);
		return (&game->tex_e);
	}
	if (ray->ray_dir_y > 0)
		return (&game->tex_n);
	return (&game->tex_s);
}

int	sample_texture(t_img *tex, int tex_x, int tex_y)
{
	char	*pixel;

	pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

t_img	*get_tex_column(t_game *game, t_ray *ray, int *tex_x)
{
	t_img	*tex;

	tex = pick_texture(game, ray);
	*tex_x = (int)(ray->wall_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		*tex_x = TEX_WIDTH - *tex_x - 1;
	return (tex);
}
