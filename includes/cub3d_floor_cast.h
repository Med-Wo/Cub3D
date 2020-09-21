/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_floor_cast.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:39:04 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 10:26:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FLOOR_CAST_H
# define CUB3D_FLOOR_CAST_H

typedef struct		s_floor_cast
{
	double	floor_wall_x;
	double	floor_wall_y;

	double	weight;

	double	current_floor_x;
	double	current_floor_y;

	int		floor_tex_x;
	int		floor_tex_y;

	double	dist_wall;

	double	dist_player;

	double	current_dist;
}					t_floor_cast;

t_floor_cast		*malloc_floor_cast(t_ray_cast *ray_cast);
t_floor_cast		create_floor_cast(t_ray_cast *ray_cast);
void				destroy_floor_cast(t_floor_cast to_destroy);
void				free_floor_cast(t_floor_cast *to_free);

#endif
