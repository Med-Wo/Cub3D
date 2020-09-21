/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:40:50 by mravily           #+#    #+#             */
/*   Updated: 2020/04/09 23:00:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector 	calc_rotate_vector(float cardi_p, float len_line)
{
	t_vector 	result;

	result.x = cosf(cardi_p) * len_line;
	result.y = -(sinf(cardi_p)) * len_line;
	return (result);
}

t_vector	calc_axis(float cardi_p, float len_line)
{
	t_vector	result;

	result.x = cosf(cardi_p - M_PI / 2) * len_line;
	result.y = -(sinf(cardi_p - M_PI / 2)) * len_line;
	return (result);
}

float				degree_to_radiant(float degree)
{
	return ((degree * M_PI) / 180.0f);
}

float calc_distance_vector(t_vector a, t_vector b)
{
	float	distance;

	distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return (distance);
}