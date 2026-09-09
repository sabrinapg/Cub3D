#include "raycast.h"
#include "libft.h"

int	is_wall(t_game *game, int map_x, int map_y)
{
	t_map	*map;

	map = &game->scene.map;
	if (map_y < 0 || map_y >= map->height)
		return (1);
	if (map_x < 0 || (size_t)map_x >= ft_strlen(map->grid[map_y]))
		return (1);
	if (map->grid[map_y][map_x] == MAP_WALL
		|| map->grid[map_y][map_x] == MAP_SPACE)
		return (1);
	return (0);
}