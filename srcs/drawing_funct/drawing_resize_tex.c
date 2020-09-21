/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_resize_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 00:35:52 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:55:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		texture_get_color(t_texture *texture, int x, int y)
{
	t_color		result;
	int			pixel_index;

	pixel_index = (x + y * texture->width) * 4;
	result = *(t_color *)(&(texture->img[pixel_index]));
	return (result);
}

void		draw_resize_tex_in_screen(t_engine *engine, t_texture *texture
	, t_vector coord, t_vector size)
{
	size_t		i;
	size_t		j;
	int			fx;
	int			fy;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			fx = i / (float)(size.x) * texture->width;
			fy = j / (float)(size.y) * texture->height;
			my_mlx_pixel_put(engine, i + (int)(coord.x)
				, j + (int)(coord.y), texture_get_color(texture, fx, fy));
			j++;
		}
		i++;
	}
}
