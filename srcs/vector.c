/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:25:39 by mravily           #+#    #+#             */
/*   Updated: 2020/01/23 20:51:30 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	create_vector(float x, float y)
{
	t_vector result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vector	*malloc_vector(float x, float y)
{
	t_vector *result;

	result = (t_vector *)malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	*result = create_vector(x, y);
	return (result);
}

void destroy_vector(t_vector to_destroy)
{
	(void)to_destroy;
}

void free_vector(t_vector *to_free)
{
	destroy_vector(*to_free);
	free(to_free);
}

float calc_distance_vector(t_vector a, t_vector b)
{
	float	distance;

	distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return (distance);
}