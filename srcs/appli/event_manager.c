/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:42:17 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 17:07:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		choice_inventory(int key, t_engine *engine)
{
	if (key == K1_KEY)
	{
		engine->player->inventory->slot_1 = true;
		engine->player->inventory->slot_2 = false;
	}
	if (key == K2_KEY)
	{
		engine->player->inventory->slot_2 = true;
		engine->player->inventory->slot_1 = false;
	}
}

void		event_pressed_bonus(int key, t_engine *engine)
{
	if (key == LSFT_KEY)
	{
		engine->event->run = true;
		engine->player->mov_speed *= 1.5;
	}
	if (key == F_KEY)
	{
		if (engine->event->fuck == true)
			engine->event->fuck = false;
		else
			engine->event->fuck = true;
	}
	if (key == LCTRL_KEY)
	{
		engine->event->shoot_left = true;
		engine->event->fuck_left = true;
		engine->bonus->weapon->part_mini_gun = 12;
	}
	if (key == RCTRL_KEY)
	{
		engine->event->shoot_right = true;
		engine->event->fuck_right = true;
		engine->bonus->weapon->part_mini_gun = 12;
	}
	choice_inventory(key, engine);
}

void		event_release_bonus(int key, t_engine *engine)
{
	if (key == LSFT_KEY)
	{
		engine->event->run = false;
		engine->player->mov_speed = engine->player->start_mov_speed;
	}
	if (key == LCTRL_KEY)
	{
		engine->event->shoot_left = false;
		if (engine->event->fuck_left == true)
			engine->event->fuck_right = false;
	}
	if (key == RCTRL_KEY)
	{
		engine->event->shoot_right = false;
		if (engine->event->fuck_right == true)
			engine->event->fuck_left = false;
	}
}

int			handle_key_release(int key, void *params)
{
	t_engine	*engine;

	engine = (t_engine *)params;
	if (engine->event->start == true)
	{
		if (key == W_KEY)
			engine->event->forward = false;
		if (key == A_KEY)
			engine->event->left = false;
		if (key == S_KEY)
			engine->event->backward = false;
		if (key == D_KEY)
			engine->event->right = false;
		if (key == LEFT_KEY)
			engine->event->rotate_left = false;
		if (key == RIGHT_KEY)
			engine->event->rotate_right = false;
		event_release_bonus(key, engine);
	}
	return (0);
}
