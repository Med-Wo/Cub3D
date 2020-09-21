/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 00:30:07 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:59:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_wall(t_engine *engine, int x, t_color color)
{
	int		y;
	int		draw_end;

	y = engine->ray_cast->draw_start;
	draw_end = engine->ray_cast->draw_end;
	while (y < draw_end)
	{
		my_mlx_pixel_put(engine, x, y, color);
		y++;
	}
}

void		my_mlx_pixel_put_int(t_engine *engine, int x, int y, int color)
{
	t_image		*image;
	char		*dst;

	if (x < 0 || x > engine->config->resolution.x
		|| y < 0 || y > engine->config->resolution.y)
		return ;
	image = engine->image;
	dst = image->addr + (y * image->line_length + x
		* (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		draw_texture_wall(t_engine *engine, t_config *config, int x)
{
	t_player	*player;
	t_image		*image;
	int			y;
	int			draw_end;

	player = engine->player;
	image = engine->image;
	draw_end = engine->ray_cast->draw_end;
	y = engine->ray_cast->draw_start;
	while (y < draw_end)
	{
		config->wall_tex_y = (int)config->tex_pos
			& (config->texture[NORTH].height - 1);
		config->tex_pos += config->step;
		my_mlx_pixel_put_int(engine, x, y
			, (int)engine->config->wall_color[config->wall_tex_y
				* config->texture[NORTH].height
				+ config->wall_tex_x]);
		y++;
	}
}

void		draw_ceiling_and_floor(t_engine *engine, int x, float height)
{
	int			draw_end;
	int			y;
	t_color		ceiling;
	t_color		floor;

	draw_end = engine->ray_cast->draw_end;
	floor = engine->config->floor_color;
	ceiling = engine->config->ceiling_color;
	if (draw_end < 0)
		draw_end = height;
	y = draw_end;
	while (y < height)
	{
		if (engine->config->ceiling_w == rgb)
			my_mlx_pixel_put(engine, x, y, floor);
		if (engine->config->floor_w == rgb)
			my_mlx_pixel_put(engine, x, height - y - 1, ceiling);
		y++;
	}
}
