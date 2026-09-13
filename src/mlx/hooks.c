/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:37:47 by dkpg-md-          #+#    #+#             */
/*   Updated: 2026/09/13 18:37:50 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"
#include "../../includes/utils.h"

int	close_hook(t_game *game)
{
	cleanup_game(game);
	free_scene(&game->scene);
	exit(0);
	return (0);
}

int	key_press_hook(int keycode, t_game *game)
{
	t_hooks	*hooks;

	hooks = &game->scene.player.hooks;
	if (keycode == KEY_ESC)
		close_hook(game);
	else if (keycode == KEY_W)
		hooks->w = true;
	else if (keycode == KEY_A)
		hooks->a = true;
	else if (keycode == KEY_S)
		hooks->s = true;
	else if (keycode == KEY_D)
		hooks->d = true;
	else if (keycode == KEY_LEFT)
		hooks->left = true;
	else if (keycode == KEY_RIGHT)
		hooks->right = true;
	return (0);
}

int	key_release_hook(int keycode, t_game *game)
{
	t_hooks	*hooks;

	hooks = &game->scene.player.hooks;
	if (keycode == KEY_W)
		hooks->w = false;
	else if (keycode == KEY_A)
		hooks->a = false;
	else if (keycode == KEY_S)
		hooks->s = false;
	else if (keycode == KEY_D)
		hooks->d = false;
	else if (keycode == KEY_LEFT)
		hooks->left = false;
	else if (keycode == KEY_RIGHT)
		hooks->right = false;
	return (0);
}
