/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 03:24:09 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:28:54 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/raycast.h"
#include "../../includes/utils.h"

static void	get_move_delta(t_hooks *hooks, t_vec *dir,
	double *move_x, double *move_y)
{
	*move_x = 0;
	*move_y = 0;
	if (hooks->w)
	{
		*move_x += dir->x * MOVE_SPEED;
		*move_y += dir->y * MOVE_SPEED;
	}
	if (hooks->s)
	{
		*move_x -= dir->x * MOVE_SPEED;
		*move_y -= dir->y * MOVE_SPEED;
	}
	if (hooks->a)
	{
		*move_x -= dir->y * MOVE_SPEED;
		*move_y += dir->x * MOVE_SPEED;
	}
	if (hooks->d)
	{
		*move_x += dir->y * MOVE_SPEED;
		*move_y -= dir->x * MOVE_SPEED;
	}
}

void	handle_input(t_game *game)
{
	t_hooks	*hooks;
	double	move_x;
	double	move_y;

	hooks = &game->scene.player.hooks;
	get_move_delta(hooks, &game->scene.player.dir, &move_x, &move_y);
	if (move_x != 0 || move_y != 0)
		move_player(game, move_x, move_y);
	if (hooks->left)
		rotate_player(game, ROT_SPEED);
	if (hooks->right)
		rotate_player(game, -ROT_SPEED);
}
