/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helmet_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:34:14 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:50:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		hlmt_get_color(t_helmet_tex *helmet, int x, int y)
{
	t_color		result;
	int			pixel_index;

	pixel_index = (x + y * helmet->width) * 4;
	result = *(t_color *)(&(helmet->addr[pixel_index]));
	return (result);
}

void		my_mlx_pixel_put_hlmt(t_img_hlmt *img_hlmt, int x
	, int y, t_color color)
{
	char		*dst;

	if (x < 0 || x >= img_hlmt->width || y < 0 || y >= img_hlmt->height)
		return ;
	dst = img_hlmt->addr + (y * img_hlmt->line_length + x
		* (img_hlmt->bits_per_pixel / 8));
	if (color.r != 0 || color.g != 0 || color.b != 0)
		*(t_color *)dst = color;
}

void		draw_hlmt_texture(t_engine *engine, int nb, t_vector coord
	, t_vector size)
{
	size_t			i;
	size_t			j;
	int				fx;
	int				fy;
	t_helmet_tex	helmet;

	helmet = engine->bonus->helmet->helmet_part[nb];
	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			fx = i / (float)(size.x) * helmet.width;
			fy = j / (float)(size.y) * helmet.height;
			my_mlx_pixel_put_hlmt(engine->bonus->helmet->img_hlmt
				, i + (int)(coord.x), j + (int)(coord.y)
				, hlmt_get_color(&engine->bonus->helmet->helmet_part[nb]
				, fx, fy));
			j++;
		}
		i++;
	}
}

void		draw_ath_texture(t_engine *engine, int nb, t_vector coord
	, t_vector size)
{
	size_t			i;
	size_t			j;
	int				fx;
	int				fy;
	t_ath_tex		ath;

	ath = engine->bonus->helmet->ath_part[nb];
	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			fx = i / (float)(size.x) * ath.width;
			fy = j / (float)(size.y) * ath.height;
			my_mlx_pixel_put_hlmt(engine->bonus->helmet->img_hlmt
				, i + (int)(coord.x), j + (int)(coord.y)
				, hlmt_get_color(&engine->bonus->helmet->ath_part[nb], fx, fy));
			j++;
		}
		i++;
	}
}
