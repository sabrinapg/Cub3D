/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:06:35 by makassa           #+#    #+#             */
/*   Updated: 2026/09/09 08:06:39 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/validation.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"
#include <fcntl.h>
#include <unistd.h>

static int	has_xpm_extension(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len <= 4)
		return (0);
	if (ft_strncmp(path + len - 4, ".xpm", 5) != 0)
		return (0);
	return (1);
}

static int	validate_texture_path(char *path)
{
	int	fd;

	if (!path)
		return (print_error("missing texture path"), 0);
	if (!has_xpm_extension(path))
		return (print_error("texture file must use .xpm extension"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error("texture file could not be opened"), 0);
	close(fd);
	return (1);
}

int	validate_texture_paths(t_textures *textures)
{
	if (!textures)
		return (print_error("missing texture configuration"), 0);
	if (!validate_texture_path(textures->north_path))
		return (0);
	if (!validate_texture_path(textures->south_path))
		return (0);
	if (!validate_texture_path(textures->west_path))
		return (0);
	if (!validate_texture_path(textures->east_path))
		return (0);
	return (1);
}

int	validate_color(t_color *color)
{
	if (!color)
		return (print_error("missing color"), 0);
	if (color->r < RGB_MIN || color->r > RGB_MAX)
		return (print_error("invalid color value"), 0);
	if (color->g < RGB_MIN || color->g > RGB_MAX)
		return (print_error("invalid color value"), 0);
	if (color->b < RGB_MIN || color->b > RGB_MAX)
		return (print_error("invalid color value"), 0);
	if (color->value < 0)
		return (print_error("missing color"), 0);
	if (color->value != ((color->r << 16) + (color->g << 8) + color->b))
		return (print_error("invalid color value"), 0);
	return (1);
}

int	validate_scene(t_scene *scene)
{
	if (!scene)
		return (print_error("missing scene"), 0);
	if (!validate_texture_paths(&scene->textures))
		return (0);
	if (!validate_color(&scene->floor))
		return (0);
	if (!validate_color(&scene->ceiling))
		return (0);
	if (!validate_map(&scene->map))
		return (0);
	return (1);
}
