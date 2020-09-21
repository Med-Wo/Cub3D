/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 01:51:15 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:59:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		welcome_get_color(t_welcome_tex *welcome, int x, int y)
{
	t_color		result;
	int			pixel_index;

	pixel_index = (x + y * welcome->width) * 4;
	result = *(t_color *)(&(welcome->addr[pixel_index]));
	return (result);
}

void		my_mlx_pixel_put_welcome_tex(t_img_welc *img_welc, int x
	, int y, t_color color)
{
	char		*dst;

	if (x < 0 || x >= img_welc->width || y < 0 || y >= img_welc->height)
		return ;
	dst = img_welc->addr + (y * img_welc->line_length
		+ x * (img_welc->bits_per_pixel / 8));
	if (color.r != 0 && color.g != 0 && color.b != 0)
		*(t_color *)dst = color;
}

void		draw_welcome_texture(t_engine *engine, t_welcome_tex *welcome
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
			fx = i / (float)(size.x) * welcome->width;
			fy = j / (float)(size.y) * welcome->height;
			my_mlx_pixel_put_welcome_tex(engine->bonus->img_welc
				, i + (int)(coord.x), j + (int)(coord.y)
				, welcome_get_color(welcome, fx, fy));
			j++;
		}
		i++;
	}
}
