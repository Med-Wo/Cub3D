/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:37:04 by mravily           #+#    #+#             */
/*   Updated: 2020/02/06 18:07:23 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_rectangle(t_appli *appli, t_vector coord, t_vector size, t_color color)
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
			my_mlx_pixel_put(appli, x, y, color);
			y++;

		}
		x++;
	}

}

void		draw_circle(t_appli *appli, t_vector coord, int radius, t_color color)
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
				my_mlx_pixel_put(appli, actual.x, actual.y, color);
			actual.y++;
		}
		actual.x++;
	}
}

void		draw_line (t_appli *appli, t_vector start, t_vector end, t_color color)
{
 	int d[2];
 	int s[2];
	int err[2];

  	s[0] = start.x < end.x ? 1 : -1;
  	s[1] = start.y < end.y ? 1 : -1;
  	d[1] = -abs (end.y - start.y);
  	d[0] =  abs (end.x - start.x);
   	err[0]= d[0] + d[1];

  while (1)
  {
    my_mlx_pixel_put(appli, start.x, start.y, color);
    if (start.x == end.x && start.y == end.y)
		break;
    err[1] = 2 * err[0];
    if (err[1] >= d[1])
	{
		err[0] += d[1];
		start.x += s[0];
	}
    if (err[1] <= d[0])
	{
		err[0] += d[0];
		start.y += s[1];
	}
  }
}

void draw_texture(t_appli *appli, t_texture *texture, t_vector coord, t_vector size)
{
	size_t i;
	size_t j;
	int fx;
	int fy;


	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			fx = i / (float)(size.x) * texture->width;
			fy = j / (float)(size.y) * texture->height;
			my_mlx_pixel_put(appli, i + (int)(coord.x), j + (int)(coord.y), texture_get_color(texture, fx, fy));
			j++;
		}
		i++;
	}
	//exit(0);
}

void            my_mlx_pixel_put(t_appli *appli, int x, int y, t_color color)
{
    char    *dst;

	if (x < 0 || x >= appli->config->resolution_size.x || y < 0 || y >= appli->config->resolution_size.y)
		return ;
    dst = appli->data->addr + (y * appli->data->line_length + x * (appli->data->bits_per_pixel / 8));
    *(t_color *)dst = color;
}
