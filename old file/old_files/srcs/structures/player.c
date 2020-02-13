/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:06:08 by mravily           #+#    #+#             */
/*   Updated: 2020/02/08 18:55:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	create_player(float x, float y)
{
	t_player result;

	result.pos = create_vector(x, y);
	result.pos_map = create_vector(x, y);
	result.dir_angle = 0.0f;
	result.rad_play = 0;
	result.dir = create_vector(x, y);

	result.plane = create_vector(0, 0.66f);

	result.rot_speed = 0;
	result.mov_speed = 0.2f;

	result.forward = false;
	result.backward = false;
	result.left = false;
	result.right = false;
	result.rotate_left = false;
	result.rotate_right = false;
	return (result);
}

t_player	*malloc_player(float x, float y)
{
	t_player *result;

	result = (t_player *)malloc(sizeof(t_player));
	if (result == NULL)
		return (NULL);
	*result = create_player(x, y);
	return (result);
}

void destroy_player(t_player to_destroy)
{
	(void)to_destroy;
}

void free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}

float		degree_to_radiant(float degree)
{
	return ((degree * M_PI) / 180.0f);
}
