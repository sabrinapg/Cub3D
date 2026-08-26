/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:24:08 by makassa           #+#    #+#             */
/*   Updated: 2026/08/25 14:28:39 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "player.h"
# include "render.h"
# define ERR_PREFIX "Error\n"

# define ID_NO "NO"
# define ID_SO "SO"
# define ID_WE "WE"
# define ID_EA "EA"
# define ID_F "F"
# define ID_C "C"

# define MAP_WALL '1'
# define MAP_EMPTY '0'
# define MAP_SPACE ' '

# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'

# define RGB_MIN 0
# define RGB_MAX 255
# define EXT_CUB ".cub"

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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_scene		scene;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
} t_game;

# endif
