/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_cast.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 22:41:03 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 10:54:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAY_CAST_H
# define CUB3D_RAY_CAST_H

# include "cub3d_vector.h"
# include "cub3d_engine.h"

typedef struct		s_ray_cast
{
	t_vector		ray_dir;
	t_vector		delta_dist;
	t_vector		side_dist;

	float			camera_x;
	float			perp_wall_dist;
	float			dir_angle;
	float			wall_x;
	unsigned int	map_x;
	unsigned int	map_y;

	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
}					t_ray_cast;

t_ray_cast			create_ray_cast(void);
t_ray_cast			*malloc_ray_cast(void);
void				destroy_ray_cast(t_ray_cast to_destroy);
void				free_ray_cast(t_ray_cast *to_free);
void				calc_ray_dir_and_delta(t_player *player
	, t_ray_cast *ray_cast, int x, float width);
void				calc_step_and_side_dist(t_player *player
	, t_ray_cast *ray_cast);
void				perform_dda(t_ray_cast *ray_cast
	, char **world_map);
void				calc_perp_wall_dist(t_ray_cast *ray_cast
	, t_player *player);
void				calc_line_height_and_draw_point(t_ray_cast *ray_cast
	, float height);
void				calculate_texture(t_ray_cast *ray_cast
	, t_player *player, t_config *config, float height);
void				calculate_color(t_ray_cast *ray_cast
	, t_player *player, t_config *config);

#endif
