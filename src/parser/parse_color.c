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

static int	skip_color_spaces(char *line, int index)
{
	while (line[index] && ft_isspace_cub(line[index]))
		index++;
	return (index);
}

static int	color_to_int(t_color *color)
{
	int	red;
	int	green;
	int	blue;

	red = color->r << 16;
	green = color->g << 8;
	blue = color->b;
	return (red + green + blue);
}

static int	parse_rgb_component(char *value, int *index, int *component)
{
	int	number;
	int	has_digit;

	number = 0;
	has_digit = 0;
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

static int	parse_rgb(char *value, t_color *color)
{
	int	index;

	index = 0;
	if (!parse_rgb_component(value, &index, &color->r))
		return (0);
	if (value[index++] != ',')
		return (0);
	if (!parse_rgb_component(value, &index, &color->g))
		return (0);
	if (value[index++] != ',')
		return (0);
	if (!parse_rgb_component(value, &index, &color->b))
		return (0);
	if (value[index])
		return (0);
	color->value = color_to_int(color);
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
	start = index;
	while (line[index] && !ft_isspace_cub(line[index]))
		index++;
	if (index == start)
		return (print_error("missing color value"), 0);
	value = ft_substr(line, start, index - start);
	if (!value)
		return (print_error("memory allocation failed"), 0);
	index = skip_color_spaces(line, index);
	if (line[index] || !parse_rgb(value, color))
		return (free(value), print_error("invalid color value"), 0);
	free(value);
	return (1);
}
