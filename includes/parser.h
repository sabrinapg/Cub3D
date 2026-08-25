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

# include "cub3D.h"

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	char	orientation;
}	t_player;

typedef struct s_textures
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
}	t_textures;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	value;
}	t_color;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_scene
{
	t_textures	textures;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_player	player;
}	t_scene;

/*
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_scene		scene;
	// image/rendering state later
}	t_game; 
*/

# endif
