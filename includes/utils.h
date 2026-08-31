/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makassa <makassa@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:27:24 by makassa           #+#    #+#             */
/*   Updated: 2026/08/26 11:32:46 by makassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

int print_error(char *message);
void init_scene(t_scene *scene);
void	free_scene(t_scene *scene);
void	free_split(char **split);
int		is_empty_line(char *line);
int		ft_isspace_cub(char c);
char	*trim_newline(char *line);
int		has_only_spaces(char *line);

# endif
