/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:27:47 by makassa           #+#    #+#             */
/*   Updated: 2026/08/31 16:27:49 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/parser.h"
#include "../../includes/utils.h"
#include "../../includes/libft.h"

static int	skip_color_spaces(char *line, int index)
{
	while (line[index] && ft_isspace_cub(line[index]))
		index++;
	return (index);
}

static int	parse_rgb_component(char *value, int *index, int *component)
{
	int	number;
	int	has_digit;

	number = 0;
	has_digit = 0;
	*index = skip_color_spaces(value, *index);
	while (value[*index] && ft_isdigit(value[*index]))
	{
		has_digit = 1;
		number = (number * 10) + (value[*index] - '0');
		if (number > RGB_MAX)
			return (0);
		*index = *index + 1;
	}
	if (!has_digit)
		return (0);
	*component = number;
	return (1);
}

static int	parse_rgb_comma(char *value, int *index)
{
	*index = skip_color_spaces(value, *index);
	if (value[*index] != ',')
		return (0);
	*index = *index + 1;
	return (1);
}

static int	parse_rgb(char *value, t_color *color)
{
	int	index;

	index = 0;
	if (!parse_rgb_component(value, &index, &color->r))
		return (0);
	if (!parse_rgb_comma(value, &index))
		return (0);
	if (!parse_rgb_component(value, &index, &color->g))
		return (0);
	if (!parse_rgb_comma(value, &index))
		return (0);
	if (!parse_rgb_component(value, &index, &color->b))
		return (0);
	index = skip_color_spaces(value, index);
	if (value[index])
		return (0);
	color->value = (color->r << 16) + (color->g << 8) + color->b;
	return (1);
}

int	parse_color(char *line, t_scene *scene)
{
	int		index;
	int		start;
	t_color	*color;
	char	*value;

	if (!line || !scene || (line[0] != ID_F[0] && line[0] != ID_C[0]))
		return (print_error("invalid color line"), 0);
	color = &scene->floor;
	if (line[0] == ID_C[0])
		color = &scene->ceiling;
	if (color->value != -1)
		return (print_error("duplicate color identifier"), 0);
	index = skip_color_spaces(line, 1);
	if (!line[index])
		return (print_error("missing color value"), 0);
	start = index;
	value = ft_substr(line, start, ft_strlen(line + start));
	if (!value)
		return (print_error("memory allocation failed"), 0);
	if (!parse_rgb(value, color))
		return (free(value), print_error("invalid color value"), 0);
	free(value);
	return (1);
}
