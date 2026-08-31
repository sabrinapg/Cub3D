/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:23:42 by makassa           #+#    #+#             */
/*   Updated: 2026/08/24 16:24:42 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

int		parse_scene(char *path, t_scene *scene);
int		read_scene_file(char *path, char ***lines);
int		count_file_lines(char *path);
char	**alloc_file_lines(int line_count);
int		append_char(char **line, char character);
int		store_line(char ***lines, char **line, int *index);
int		parse_config_lines(char **lines, t_scene *scene, int *map_start);
int		parse_identifier_line(char *line, t_scene *scene);
int		is_identifier_line(char *line);
int		is_map_line(char *line);
int		parse_texture(char *line, t_scene *scene);
int		parse_color(char *line, t_scene *scene);
int		parse_map(char **lines, int start, t_scene *scene);

# endif
