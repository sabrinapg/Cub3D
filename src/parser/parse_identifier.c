/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:34:00 by makassa           #+#    #+#             */
/*   Updated: 2026/08/26 11:34:00 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"

static int	skip_spaces(char *line)
{
	int	index;

	index = 0;
	while (line[index] && ft_isspace_cub(line[index]))
		index++;
	return (index);
}

int	is_map_line(char *line)
{
	int	index;

	if (!line)
		return (0);
	index = skip_spaces(line);
	if (line[index] == MAP_WALL || line[index] == MAP_EMPTY)
		return (1);
	if (line[index] == PLAYER_N || line[index] == PLAYER_S)
		return (1);
	if (line[index] == PLAYER_E || line[index] == PLAYER_W)
		return (1);
	return (0);
}

int	is_identifier_line(char *line)
{
	int	index;

	if (!line)
		return (0);
	index = skip_spaces(line);
	if (!ft_strncmp(line + index, ID_NO, 2) && ft_isspace_cub(line[index + 2]))
		return (1);
	if (!ft_strncmp(line + index, ID_SO, 2) && ft_isspace_cub(line[index + 2]))
		return (1);
	if (!ft_strncmp(line + index, ID_WE, 2) && ft_isspace_cub(line[index + 2]))
		return (1);
	if (!ft_strncmp(line + index, ID_EA, 2) && ft_isspace_cub(line[index + 2]))
		return (1);
	if (line[index] == ID_F[0] && ft_isspace_cub(line[index + 1]))
		return (1);
	if (line[index] == ID_C[0] && ft_isspace_cub(line[index + 1]))
		return (1);
	return (0);
}

int	parse_identifier_line(char *line, t_scene *scene)
{
	int	index;

	if (!is_identifier_line(line))
		return (print_error("unknown scene identifier"));
	index = skip_spaces(line);
	if (!ft_strncmp(line + index, ID_NO, 2))
		return (parse_texture(line + index, scene));
	if (!ft_strncmp(line + index, ID_SO, 2))
		return (parse_texture(line + index, scene));
	if (!ft_strncmp(line + index, ID_WE, 2))
		return (parse_texture(line + index, scene));
	if (!ft_strncmp(line + index, ID_EA, 2))
		return (parse_texture(line + index, scene));
	if (line[index] == ID_F[0])
		return (parse_color(line + index, scene));
	if (line[index] == ID_C[0])
		return (parse_color(line + index, scene));
	return (0);
}

int	parse_config_lines(char **lines, t_scene *scene, int *map_start)
{
	int	index;

	index = 0;
	while (lines[index])
	{
		if (is_empty_line(lines[index]))
			index++;
		else if (is_map_line(lines[index]))
		{
			*map_start = index;
			return (1);
		}
		else if (!parse_identifier_line(lines[index], scene))
			return (0);
		else
			index++;
	}
	return (print_error("scene file does not contain a map"));
}
