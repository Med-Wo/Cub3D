/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_raycast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 22:51:24 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:42:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des elements de la structure t_ray_cast
*/

void		destroy_ray_cast(t_ray_cast to_destroy)
{
	to_destroy.ray_dir = create_vector(0, 0);
	to_destroy.delta_dist = create_vector(0, 0);
	to_destroy.side_dist = create_vector(0, 0);
	to_destroy.camera_x = 0;
	to_destroy.perp_wall_dist = 0;
	to_destroy.dir_angle = 0;
	to_destroy.map_x = 0;
	to_destroy.map_y = 0;
	to_destroy.step_x = 0;
	to_destroy.step_y = 0;
	to_destroy.side = 0;
	to_destroy.line_height = 0;
	to_destroy.draw_start = 0;
	to_destroy.draw_end = 0;
}

/*
** Free de la structure t_raycast
*/

void		free_ray_cast(t_ray_cast *to_free)
{
	destroy_ray_cast(*to_free);
	free(to_free);
}
