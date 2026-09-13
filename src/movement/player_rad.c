/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 03:44:47 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:28:40 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/raycast.h"
#include "../../includes/utils.h"

void	move_player(t_game *game, double move_x, double move_y)
{
	t_player	*player;
	double		new_x;
	double		new_y;
	double		buf_x;
	double		buf_y;

	player = &game->scene.player;
	new_x = player->pos.x + move_x;
	new_y = player->pos.y + move_y;
	if (move_x > 0)
		buf_x = PLAYER_RADIUS;
	else
		buf_x = -PLAYER_RADIUS;
	if (move_y > 0)
		buf_y = PLAYER_RADIUS;
	else
		buf_y = -PLAYER_RADIUS;
	if (!is_wall(game, (int)(new_x + buf_x), (int)player->pos.y)
		&& !is_wall(game, (int)(new_x + buf_x), (int)new_y))
		player->pos.x = new_x;
	if (!is_wall(game, (int)player->pos.x, (int)(new_y + buf_y))
		&& !is_wall(game, (int)new_x, (int)(new_y + buf_y)))
		player->pos.y = new_y;
}
