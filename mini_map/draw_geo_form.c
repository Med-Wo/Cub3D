/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_geo_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:46:19 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:46:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
draw_rectangle(t_engine *engine, t_vector coord, t_vector size, t_color color)
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
			my_mlx_pixel_put(engine, x, y, color);
			y++;

		}
		x++;
	}

}

void
draw_circle(t_engine *engine, t_vector coord, int radius, t_color color)
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
				my_mlx_pixel_put(engine, actual.x, actual.y, color);
			actual.y++;
		}
		actual.x++;
	}
}

void
draw_line(t_engine *engine, t_vector start, t_vector end, t_color color)
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
		my_mlx_pixel_put(engine, start.x, start.y, color);
		i++;
	}
}

void
bress_line(t_engine *engine, t_vector start, t_vector end, t_color color)
{
 	int d[2];
 	int s[2];
	int err[2];

  	s[0] = start.x < end.x ? 1 : -1;
  	s[1] = start.y < end.y ? 1 : -1;
  	d[1] = -abs((int)end.y - (int)start.y);
  	d[0] =  abs((int)end.x - (int)start.x);
   	err[0]= d[0] + d[1];
  	while (1)
  	{
    	my_mlx_pixel_put(engine, start.x, start.y, color);
    	if (start.x == end.x && start.y == end.y)
		break;
    	err[1] = 2 * err[0];
    	if (err[1] > d[1])
		{
			err[0] += d[1];
			start.x += s[0];
		}
		if (err[1] < d[0])
		{
			err[0] += d[0];
			start.y += s[1];
		}
 	 }
}