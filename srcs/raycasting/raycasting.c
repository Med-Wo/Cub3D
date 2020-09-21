/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 17:39:35 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 19:27:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			draw_floor_ceiling(t_engine *engine, float height, int x)
{
	floor_casting(engine, height, x);
	draw_ceiling_and_floor(engine, x, height);
}

void				raycasting(t_engine *engine)
{
	int			x;
	float		width;
	float		height;
	char		**world_map;

	width = engine->config->resolution.x;
	height = engine->config->resolution.y;
	world_map = engine->config->map;
	x = 0;
	while (x < width)
	{
		calc_ray_dir_and_delta(engine->player, engine->ray_cast, x, width);
		calc_step_and_side_dist(engine->player, engine->ray_cast);
		perform_dda(engine->ray_cast, world_map);
		calc_perp_wall_dist(engine->ray_cast, engine->player);
		calc_line_height_and_draw_point(engine->ray_cast, height);
		calculate_texture(engine->ray_cast, engine->player
			, engine->config, height);
		calculate_color(engine->ray_cast, engine->player, engine->config);
		draw_floor_ceiling(engine, height, x);
		draw_texture_wall(engine, engine->config, x);
		engine->sprite_cast->z_buffer[x] = engine->ray_cast->perp_wall_dist;
		x++;
	}
	sprite_casting(engine);
}
