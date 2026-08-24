#include "cub3d.h"

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
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;

	if (ray->side == 0)
		color = 0xAA0000;   // darker red — E/W wall
	else
		color = 0xFF4444;   // lighter red — N/S wall
	y = 0;
	while (y < ray->draw_start)
		put_pixel(&game->screen, x, y++, 0x333333);  // ceiling
	while (y < ray->draw_end)
		put_pixel(&game->screen, x, y++, color);      // wall
	while (y < WIN_HEIGHT)
		put_pixel(&game->screen, x, y++, 0x777777);   // floor
}