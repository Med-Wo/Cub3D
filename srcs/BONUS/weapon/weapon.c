/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:20:25 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:10:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draw le fuck a l'ecran en fonction de la touche tir appuyer
*/

void		fuck(t_engine *engine)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(engine->config->resolution.x / 2.7
			, engine->config->resolution.y / 1.36);
	size = create_vector(engine->config->resolution.x / 3.8
			, engine->config->resolution.y / 3.8);
	if (engine->event->shoot_right == true
		&& engine->event->fuck_right == true)
		draw_weapon_texture(engine, 1, pos, size);
	else if (engine->event->shoot_right == false
		&& engine->event->fuck_right == true
		&& engine->event->shoot_left == false
		&& engine->event->fuck_left == false)
		draw_weapon_texture(engine, 0, pos, size);
	else if (engine->event->shoot_left == true
		&& engine->event->fuck_left == true)
		draw_weapon_texture(engine, 3, pos, size);
	else if (engine->event->shoot_left == false
		&& engine->event->fuck_left == true
		&& engine->event->shoot_right == false
		&& engine->event->fuck_right == false)
		draw_weapon_texture(engine, 2, pos, size);
}

/*
** Draw les poings et l'animation des coup de poings
*/

void		melee(t_engine *engine)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(engine->config->resolution.x / 2.665
			, engine->config->resolution.y / 1.348);
	size = create_vector(engine->config->resolution.x / 3.8
			, engine->config->resolution.y / 3.8);
	if (engine->event->shoot_right == false
		&& engine->event->shoot_left == false)
		draw_weapon_texture(engine, 9, pos, size);
	else if (engine->event->shoot_right == true)
		draw_weapon_texture(engine, 10, pos, size);
	else if (engine->event->shoot_left == true)
		draw_weapon_texture(engine, 11, pos, size);
}

/*
** Animation de la chauffe et du tir du mini_gun
*/

void		mini_gun_firing(t_engine *engine, t_vector pos, t_vector size)
{
	if (engine->bonus->weapon->part_mini_gun >= 16
		&& engine->bonus->weapon->part_mini_gun <= 19
		&& engine->player->inventory->ammo != 0)
	{
		wait_time(20);
		draw_weapon_texture(engine, engine->bonus->weapon->part_mini_gun
			, pos, size);
		if ((engine->bonus->weapon->part_mini_gun += 1) == 19)
			engine->bonus->weapon->part_mini_gun = 16;
		else
			engine->bonus->weapon->part_mini_gun += 1;
		engine->player->inventory->ammo -= 1;
	}
	else if (engine->bonus->weapon->part_mini_gun < 16
			&& engine->player->inventory->ammo != 0)
	{
		wait_time(30);
		draw_weapon_texture(engine, engine->bonus->weapon->part_mini_gun
			, pos, size);
		engine->bonus->weapon->part_mini_gun += 1;
	}
	else
		fuck(engine);
}

void		mini_gun(t_engine *engine)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(engine->config->resolution.x / 2.665
			, engine->config->resolution.y / 1.348);
	size = create_vector(engine->config->resolution.x / 3.8
		, engine->config->resolution.y / 3.8);
	if (engine->event->shoot_right == false
		&& engine->event->shoot_left == false)
		draw_weapon_texture(engine, 13, pos, size);
	if (engine->event->shoot_right == true
		|| engine->event->shoot_left == true)
		mini_gun_firing(engine, pos, size);
}

/*
** Draw l'arme en fonction de la du slot en cours
*/

void		weapon(t_engine *engine)
{
	if (engine->player->inventory->slot_1 == true)
	{
		if (engine->event->fuck == true)
			fuck(engine);
		else
			melee(engine);
	}
	if (engine->player->inventory->slot_2 == true)
	{
		if (engine->player->inventory->mini_gun == true)
			mini_gun(engine);
		else
			melee(engine);
	}
}
