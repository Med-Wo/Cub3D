/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:28:48 by mravily           #+#    #+#             */
/*   Updated: 2020/04/02 19:42:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	draw_axis(t_engine *engine, int call)
{
	t_vector 	end_o;
	t_vector 	end_a;
	
	end_o = create_vector(engine->player->fov->fov_c.x
	+ engine->player->pos_map.x, engine->player->fov->fov_c.y
	+ engine->player->pos_map.y);
	end_a = create_vector(engine->player->fov->axis.x
	+ engine->player->pos_map.x, engine->player->fov->axis.y
	+ engine->player->pos_map.y);
	if (call == 1)
	{
		/* axe ordonne */
		draw_line(engine, engine->player->pos_map
		, end_o, create_color(0, 0, 255));
		/* axe abscisse */
		draw_line(engine, engine->player->pos_map
		, end_a, create_color(0, 0, 255));
	}
	else
	{
		/* axe ordonne */
		draw_line_on_mini_map(engine
		, engine->player->pos_map, end_o, create_color(0, 0, 255));
		/* axe abscisse */
		draw_line_on_mini_map(engine
		, engine->player->pos_map, end_a, create_color(0, 0, 255));
	}
	
}

void 	draw_player(t_engine *engine, int call)
{
	if (call == 1)
		draw_circle(engine, engine->player->pos_map
		, engine->player->rad_play, create_color(0, 0, 255));
	else
		draw_circle_on_mini_map(engine, engine->player->pos_map
		, engine->player->rad_play, create_color(0, 0, 255));
	draw_axis(engine, call);
	draw_fov(engine, call);
}

void 		draw_fov(t_engine *engine, int call)
{
	if (call == 1)
	{
		/* Branche gauche */
		draw_line(engine, engine->player->pos_map
		, create_vector(engine->player->fov->fov_l.x
		+ engine->player->pos_map.x, engine->player->fov->fov_l.y
		+ engine->player->pos_map.y), create_color(0, 0, 255));
		/* Branche droite */
		draw_line(engine, engine->player->pos_map
		, create_vector(engine->player->fov->fov_r.x
		+ engine->player->pos_map.x, engine->player->fov->fov_r.y
		+ engine->player->pos_map.y), create_color(0, 0, 255));
	}
	else
	{
		/* Branche gauche */
		draw_line_on_mini_map(engine
		, engine->player->pos_map
		, create_vector(engine->player->fov->fov_l.x
		+ engine->player->pos_map.x, engine->player->fov->fov_l.y
		+ engine->player->pos_map.y), create_color(0, 0, 255));
		/* Branche droite */
		draw_line_on_mini_map(engine
		, engine->player->pos_map
		, create_vector(engine->player->fov->fov_r.x
		+ engine->player->pos_map.x, engine->player->fov->fov_r.y
		+ engine->player->pos_map.y), create_color(0, 0, 255));
	}
	
}
