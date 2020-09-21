/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_ray_cast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 22:45:30 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:45:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisaton de la structure
*/

t_ray_cast		create_ray_cast(void)
{
	t_ray_cast	result;

	result.ray_dir = create_vector(0, 0);
	result.delta_dist = create_vector(0, 0);
	result.side_dist = create_vector(0, 0);
	result.camera_x = 0;
	result.perp_wall_dist = 0;
	result.dir_angle = 0;
	result.map_x = 0;
	result.map_y = 0;
	result.step_x = 0;
	result.step_y = 0;
	result.side = 0;
	result.line_height = 0;
	result.draw_start = 0;
	result.draw_end = 0;
	return (result);
}

/*
** Mallocage de la structure
*/

t_ray_cast		*malloc_ray_cast(void)
{
	t_ray_cast	*result;

	result = (t_ray_cast *)malloc(sizeof(t_ray_cast));
	if (result == NULL)
		return (NULL);
	*result = create_ray_cast();
	return (result);
}
