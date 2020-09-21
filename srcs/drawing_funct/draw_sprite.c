/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:18:03 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 14:57:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draw le pixel du sprite
*/

static void		my_mlx_pixel_put_sprite(t_engine *engine, int x
	, int y, int color)
{
	t_image		*image;
	char		*dst;

	image = engine->image;
	dst = image->addr + (y * image->line_length + x
		* (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			draw_pixel_sprite(t_engine *engine, int stripe
	, int draw_start_y, int i)
{
	my_mlx_pixel_put_sprite(engine, stripe, draw_start_y
		, (int)engine->config->sprite_color
		[engine->config->texture
		[engine->config->sprite[i].id_texture].width
		* engine->sprite_cast->tex_y
		+ engine->sprite_cast->tex_x]);
}

static void		get_place(t_engine *engine, int draw_start_y
	, int stripe, int i)
{
	init_tex_y(engine->sprite_cast, engine->config, draw_start_y, i);
	engine->config->sprite_color = engine->config->texture
		[engine->config->sprite[i].id_texture].color;
	if ((engine->config->sprite_color
		[engine->config->texture
		[engine->config->sprite[i].id_texture].width
		* engine->sprite_cast->tex_y
			+ engine->sprite_cast->tex_x] & 0x00FFFFFF) != 0
		&& engine->config->sprite[i].active == true)
		draw_pixel_sprite(engine, stripe, draw_start_y, i);
}

static int		get_place_2(t_engine *engine, int draw_start_y
	, int stripe, int i)
{
	draw_start_y = engine->sprite_cast->draw_start_y;
	while (draw_start_y < engine->sprite_cast->draw_end_y)
	{
		get_place(engine, draw_start_y, stripe, i);
		draw_start_y++;
	}
	return (draw_start_y);
}

/*
** Algo pour draw le sprite
*/

void			draw_sprite(t_engine *engine, int i)
{
	int				stripe;
	int				draw_end_x;
	int				draw_start_y;
	t_ray_cast		*ray_cast;

	ray_cast = engine->ray_cast;
	stripe = engine->sprite_cast->draw_start_x;
	draw_end_x = engine->sprite_cast->draw_end_x;
	while (stripe < draw_end_x)
	{
		init_tex_x(engine->sprite_cast, engine->config, stripe, i);
		if (engine->sprite_cast->transform_y > 0
			&& stripe > 0
			&& stripe < engine->config->resolution.x
			&& engine->sprite_cast->transform_y
				< engine->sprite_cast->z_buffer[stripe])
		{
			draw_start_y = get_place_2(engine, draw_start_y, stripe, i);
		}
		stripe++;
	}
}
