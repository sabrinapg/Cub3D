/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:34:00 by makassa           #+#    #+#             */
/*   Updated: 2026/08/25 14:34:43 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "cub3d.h"

int		validate_scene(t_scene *scene);
int		validate_texture_paths(t_textures *textures);
int		validate_color(t_color *color);
int		validate_map(t_map *map);
int		validate_map_chars(t_map *map);
int		validate_player_count(t_map *map);
int		validate_no_empty_map_lines(t_map *map);
int		validate_map_closed(t_map *map);
char	**duplicate_map_grid(t_map *map);

# endif
