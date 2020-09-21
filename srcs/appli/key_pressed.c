/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:08:18 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 17:09:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		bool_move(t_engine *engine, int key)
{
	if (key == W_KEY)
		engine->event->forward = true;
	if (key == A_KEY)
		engine->event->left = true;
	if (key == S_KEY)
		engine->event->backward = true;
	if (key == D_KEY)
		engine->event->right = true;
	if (key == LEFT_KEY)
		engine->event->rotate_left = true;
	if (key == RIGHT_KEY)
		engine->event->rotate_right = true;
}

int				handle_key_pressed(int key, void *params)
{
	t_engine *engine;

	engine = (t_engine *)params;
	if (key == ESC_KEY)
		exit_cub();
	re_set_dir_player(key, engine->player, engine->event);
	if (engine->event->start == true)
	{
		bool_move(engine, key);
		event_pressed_bonus(key, engine);
	}
	if (engine->player->health == 0)
	{
		if (key == RTN_KEY)
		{
			engine->player->dir = engine->player->start_dir;
			engine->player->plane = engine->player->start_plane;
			engine->player->pos = engine->player->start_pos;
			engine->player->health = 100;
		}
	}
	return (0);
}
