/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_drawing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:41:55 by mravily           #+#    #+#             */
/*   Updated: 2020/04/11 23:31:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_rectangle_on_mini_map(t_engine *engine, t_vector coord
	, t_vector size, t_color color)
{
	int x;
	int y;
	int target_x;
	int target_y;

	target_x = coord.x + size.x;
	target_y = coord.y + size.y;
	x = coord.x;
	while(x < target_x)
	{
		y = coord.y;
		while(y < target_y)
		{
			my_mlx_pixel_put_on_mini_map(engine->bonus->mini_map, x, y, color);
			y++;
		}
		x++;
	}

}

void		draw_circle_on_mini_map(t_engine *engine, t_vector coord
	,int radius, t_color color)
{
	t_vector	actual;
	int 		target_x;
	int 		target_y;

	target_x = coord.x + radius;
	target_y = coord.y + radius;
	actual.x = coord.x - radius;
	while(actual.x < target_x)
	{
		actual.y = coord.y - radius;
		while(actual.y < target_y)
		{
			if (calc_distance_vector(coord, actual) <= radius)
				my_mlx_pixel_put_on_mini_map(engine->bonus->mini_map
					, actual.x, actual.y, color);
			actual.y++;
		}
		actual.x++;
	}
}

void draw_line_on_mini_map(t_engine *engine, t_vector start, t_vector end, t_color color)
{
	float 		dest_x;
	float 		dest_y;
	float 		step;
	size_t 		i;
	t_vector 	increment;
	
	dest_x = end.x - start.x;
	dest_y = end.y - start.y;
	if (abs((int)dest_x) > abs((int)dest_y))
		step = abs((int)dest_x);
	else
		step = abs((int)dest_y);
	increment.x = dest_x / (float)step;
	increment.y = dest_y / (float)step;
	i = 0;
	while (i < step)
	{
		start.x += increment.x;
		start.y += increment.y;
		my_mlx_pixel_put_on_mini_map(engine->bonus->mini_map, start.x, start.y, color);
		i++;
	}
}

void            my_mlx_pixel_put_on_mini_map(t_mini_map *mini_map, int x
	, int y, t_color color)
{
    char    *dst;
	if (x < 0 || x >= mini_map->width || y < 0 || y >= mini_map->height)
		return ;
    dst = mini_map->addr + (y * mini_map->line_length + x
		* (mini_map->bits_per_pixel / 8));
    *(t_color *)dst = color;
}
