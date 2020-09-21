/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_floor_cast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 19:02:23 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 16:41:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mallocage de la strucuture floor_cast
*/

t_floor_cast		*malloc_floor_cast(t_ray_cast *ray_cast)
{
	t_floor_cast	*floor_cast;

	floor_cast = (t_floor_cast *)malloc(sizeof(t_floor_cast));
	if (floor_cast == NULL)
		return (NULL);
	*floor_cast = create_floor_cast(ray_cast);
	return (floor_cast);
}

/*
** Initialisation des valeurs a zero des valeurs de la structure
*/

t_floor_cast		create_floor_cast(t_ray_cast *ray_cast)
{
	t_floor_cast	floor_cast;

	floor_cast.floor_tex_x = 0;
	floor_cast.floor_tex_y = 0;
	floor_cast.weight = 0;
	floor_cast.current_floor_x = 0;
	floor_cast.current_floor_y = 0;
	floor_cast.floor_tex_x = 0;
	floor_cast.floor_tex_y = 0;
	floor_cast.dist_wall = ray_cast->perp_wall_dist;
	floor_cast.dist_player = 0;
	floor_cast.current_floor_y = 0;
	return (floor_cast);
}
