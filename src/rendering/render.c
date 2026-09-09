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

static t_img	*pick_texture(t_game *game, t_ray *ray)
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

static int	sample_texture(t_img *tex, int tex_x, int tex_y)
{
	char	*pixel;

	pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_img	*tex;
	int		tex_x;
	int		tex_y;
	int		y;
	double	step;
	double	tex_pos;

	tex = pick_texture(game, ray);
	tex_x = (int)(ray->wall_x * TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = TEX_WIDTH - tex_x - 1;
	y = 0;
	while (y < ray->draw_start)
		put_pixel(&game->screen, x, y++, game->scene.ceiling.value);
	step = (double)TEX_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		put_pixel(&game->screen, x, y++, sample_texture(tex, tex_x, tex_y));
	}
	while (y < WIN_HEIGHT)
		put_pixel(&game->screen, x, y++, game->scene.floor.value);
}