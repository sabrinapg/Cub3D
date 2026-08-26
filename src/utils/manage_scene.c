/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:01:31 by makassa           #+#    #+#             */
/*   Updated: 2026/08/26 13:08:45 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../../includes/cub3d.h"
# include "../../includes/libft.h"

int	print_error(char *message)
{
  ft_putstr_fd(ERR_PREFIX, 1);
  ft_putstr_fd(message, 1);
  ft_putstr_fd("\n", 1);
  return (1);
}






void	init_scene(t_scene *scene);
void	free_scene(t_scene *scene);
void	free_split(char **split);
