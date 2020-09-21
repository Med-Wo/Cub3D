/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_helmet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 01:06:09 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:45:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draw le logo de run a l'ecran
*/

void		draw_ath_run(t_engine *engine)
{
	if (engine->event->run == true)
	{
		draw_hlmt_texture(engine, 16
			, create_vector(engine->config->resolution.x / 23
				, engine->config->resolution.y / 1.4)
			, create_vector(engine->config->resolution.x / 10
				, engine->config->resolution.y / 10));
	}
}

/*
** Draw l'ATH Health bar et Shield Bar
*/

void		draw_shield_health(t_engine *engine)
{
	draw_health(engine);
	compteur_health(engine);
	compteur_shield(engine);
	if (engine->player->shield >= 25 && engine->player->shield <= 100)
		draw_green_shield(engine);
	if (engine->player->shield >= 125 && engine->player->shield <= 200)
		draw_blue_shield(engine);
}

/*
** Draw le compteur de munition
*/

void		draw_number_ammo(t_engine *engine)
{
	t_vector		pos;
	t_vector		size;

	pos = create_vector(engine->config->resolution.x / 1.34
		, engine->config->resolution.y / 1.16);
	size = create_vector(engine->config->resolution.x / 10
				, engine->config->resolution.y / 10);
	draw_ath_texture(engine, engine->player->inventory->ammo, pos, size);
}

/*
** Draw les trois parties du HUD du casque
*/

void		draw_hud_helmet(t_engine *engine)
{
	t_vector		size_hud;

	size_hud = create_vector(engine->config->resolution.x / 2.6
			, engine->config->resolution.y / 3.8);
	draw_hlmt_texture(engine, 13
			, create_vector(0, 0)
			, create_vector(engine->config->resolution.x
			, engine->config->resolution.y / 9));
	draw_hlmt_texture(engine, 14
			, create_vector(0
			, engine->config->resolution.y / 1.35)
			, size_hud);
	draw_hlmt_texture(engine, 15
			, create_vector(engine->config->resolution.x / 1.6
			, engine->config->resolution.y / 1.35)
			, size_hud);
}

/*
** Algo pour animation de mise en place du casque
*/

void		put_on_the_helmet(t_engine *engine)
{
	t_vector		coord;
	t_vector		size;

	coord = create_vector(0, 0);
	size = create_vector(engine->config->resolution.x
		, engine->config->resolution.y);
	if (engine->bonus->helmet->id_part_helmet != 12)
	{
		wait_time(20);
		draw_hlmt_texture(engine, engine->bonus->helmet->id_part_helmet
			, coord, size);
		engine->bonus->helmet->id_part_helmet += 1;
	}
	else
	{
		draw_ath_run(engine);
		draw_hud_helmet(engine);
		sound_put_on_helmet(engine->bonus->helmet);
		draw_shield_health(engine);
		weapon(engine);
		draw_number_ammo(engine);
	}
}
