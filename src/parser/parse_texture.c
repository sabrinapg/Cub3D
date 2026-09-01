/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:27:38 by makassa           #+#    #+#             */
/*   Updated: 2026/08/31 16:27:40 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/parser.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"

static int	is_texture_identifier(char *id)
{
	if (!ft_strncmp(id, ID_NO, 2))
		return (1);
	if (!ft_strncmp(id, ID_SO, 2))
		return (1);
	if (!ft_strncmp(id, ID_WE, 2))
		return (1);
	if (!ft_strncmp(id, ID_EA, 2))
		return (1);
	return (0);
}

static int	skip_texture_spaces(char *line, int index)
{
	while (line[index] && ft_isspace_cub(line[index]))
		index++;
	return (index);
}

int	set_texture_path(char *id, char *path, t_scene *scene)
{
	char	**texture_path;

	texture_path = NULL;
	if (!ft_strncmp(id, ID_NO, 2))
		texture_path = &scene->textures.north_path;
	else if (!ft_strncmp(id, ID_SO, 2))
		texture_path = &scene->textures.south_path;
	else if (!ft_strncmp(id, ID_WE, 2))
		texture_path = &scene->textures.west_path;
	else if (!ft_strncmp(id, ID_EA, 2))
		texture_path = &scene->textures.east_path;
	if (!texture_path)
		return (print_error("invalid texture identifier"));
	if (*texture_path)
		return (print_error("duplicate texture identifier"));
	*texture_path = path;
	return (1);
}

int	parse_texture(char *line, t_scene *scene)
{
	int		index;
	int		start;
	char	*path;

	if (!line || !scene || !is_texture_identifier(line))
		return (print_error("invalid texture line"));
	index = skip_texture_spaces(line, 2);
	start = index;
	while (line[index] && !ft_isspace_cub(line[index]))
		index++;
	if (index == start)
		return (print_error("missing texture path"));
	path = ft_substr(line, start, index - start);
	if (!path)
		return (print_error("memory allocation failed"));
	index = skip_texture_spaces(line, index);
	if (line[index])
	{
		free(path);
		return (print_error("texture line has too many arguments"));
	}
	if (!set_texture_path(line, path, scene))
	{
		free(path);
		return (0);
	}
	return (1);
}
