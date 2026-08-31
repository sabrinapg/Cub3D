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

void	init_scene(t_scene *scene)
{
  if(!scene)
    return ;
  scene->textures.north_path = NULL;
  scene->textures.south_path = NULL;
  scene->textures.east_path = NULL;
  scene->textures.west_path = NULL;
  scene->floor.r = -1;
  scene->floor.g = -1;
  scene->floor.b = -1;
  scene->floor.value = -1;
  scene->ceiling.r = -1;
  scene->ceiling.g = -1;
  scene->ceiling.b = -1;
  scene->ceiling.value = -1;
  scene->map.grid = NULL;
  scene->map.height = 0;
  scene->map.width = 0;
}

void	free_scene(t_scene *scene)
{
  int index;
  if (!scene)
    return ;
  free(scene->textures.north_path);
  free(scene->textures.south_path);
  free(scene->textures.east_path);
  free(scene->textures.west_path);
  if(scene->map.grid)
  {
    index = 0;
    while(scene->map.grid[index])
    {
      free(scene->map.grid[index]);
      index++;
    }
    free(scene->map.grid);
  }
  init_scene(scene);
}

void	free_split(char **split)
{
  int index;

  if(!split)
    return ;
  index = 0;
  while(split[index])
  {
    free(split[index]);
    index++;
  }
  free(split);
}
