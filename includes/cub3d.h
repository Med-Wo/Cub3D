/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:00:44 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 09:12:01 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"

# include "cub3d_define.h"

# include "cub3d_color.h"
# include "cub3d_vector.h"

# include "cub3d_config.h"
# include "cub3d_engine.h"

# include "cub3d_vars.h"
# include "cub3d_image.h"
# include "cub3d_player.h"
# include "cub3d_event.h"
# include "cub3d_ray_cast.h"
# include "cub3d_floor_cast.h"
# include "cub3d_sprite_cast.h"
# include "cub3d_bonus.h"

# include "cub3d_appli.h"
# include "cub3d_drawing.h"

# include "cub3d_parsing.h"

# include "libft.h"

# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

bool		is_not_wall(t_vector index, char **map);
bool		is_cardi_point(t_vector index, char **map);

int			exit_cub();
void		error_exit_cub(char *line, char *error, char *message);
void		draw_map(t_engine *engine, int call);
void		print_parsing_cub(t_config *config, t_player *player);

#endif
