/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:25:31 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:53:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Dessine le compteur de la shield bar
*/

void		compteur_shield(t_engine *engine)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(engine->config->resolution.x / 3.6
			, engine->config->resolution.y / 1.11);
	size = create_vector(engine->config->resolution.x / 19
			, engine->config->resolution.y / 17);
	if (engine->player->shield == 0)
		draw_ath_texture(engine, 0, pos, size);
	if (engine->player->shield == 25)
		draw_ath_texture(engine, 25, pos, size);
	if (engine->player->shield == 50)
		draw_ath_texture(engine, 38, pos, size);
	if (engine->player->shield == 75)
		draw_ath_texture(engine, 39, pos, size);
	if (engine->player->shield == 100)
		draw_ath_texture(engine, 40, pos, size);
	if (engine->player->shield == 125)
		draw_ath_texture(engine, 41, pos, size);
	if (engine->player->shield == 150)
		draw_ath_texture(engine, 42, pos, size);
	if (engine->player->shield == 175)
		draw_ath_texture(engine, 43, pos, size);
	if (engine->player->shield == 200)
		draw_ath_texture(engine, 44, pos, size);
}

/*
** Dessine le compteur de la health bar
*/

void		compteur_health(t_engine *engine)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(engine->config->resolution.x / 3.6
			, engine->config->resolution.y / 1.18);
	size = create_vector(engine->config->resolution.x / 19
			, engine->config->resolution.y / 17);
	if (engine->player->health == 0)
		draw_ath_texture(engine, 0, pos, size);
	if (engine->player->health == 25)
		draw_ath_texture(engine, 25, pos, size);
	if (engine->player->health == 50)
		draw_ath_texture(engine, 38, pos, size);
	if (engine->player->health == 75)
		draw_ath_texture(engine, 39, pos, size);
	if (engine->player->health == 100)
		draw_ath_texture(engine, 40, pos, size);
}

/*
** Dessine a l'ecran les differents pallier du shield blue
*/

void		draw_blue_shield(t_engine *engine)
{
	t_vector	coord_shield;
	t_vector	size;

	coord_shield = create_vector(engine->config->resolution.x / 5
			, engine->config->resolution.y / 1.14);
	size = create_vector(engine->config->resolution.x / 13
				, engine->config->resolution.y / 12);
	if (engine->player->shield == 125)
		draw_ath_texture(engine, 34, coord_shield, size);
	if (engine->player->shield == 150)
		draw_ath_texture(engine, 35, coord_shield, size);
	if (engine->player->shield == 175)
		draw_ath_texture(engine, 36, coord_shield, size);
	if (engine->player->shield == 200)
		draw_ath_texture(engine, 37, coord_shield, size);
}

/*
** Dessine a l'ecran les differents pallier du shield green
*/

void		draw_green_shield(t_engine *engine)
{
	t_vector	coord_shield;
	t_vector	size;

	coord_shield = create_vector(engine->config->resolution.x / 5
			, engine->config->resolution.y / 1.14);
	size = create_vector(engine->config->resolution.x / 13
			, engine->config->resolution.y / 12);
	if (engine->player->shield == 25)
		draw_ath_texture(engine, 30, coord_shield, size);
	if (engine->player->shield == 50)
		draw_ath_texture(engine, 31, coord_shield, size);
	if (engine->player->shield == 75)
		draw_ath_texture(engine, 32, coord_shield, size);
	if (engine->player->shield == 100)
		draw_ath_texture(engine, 33, coord_shield, size);
}

/*
** Dessine a l'ecran les differents pallier de la health bar
*/

void		draw_health(t_engine *engine)
{
	t_vector	coord_health;
	t_vector	size;

	coord_health = create_vector(engine->config->resolution.x / 4.9
			, engine->config->resolution.y / 1.24);
	size = create_vector(engine->config->resolution.x / 14
			, engine->config->resolution.y / 10);
	if (engine->player->health == 25)
		draw_ath_texture(engine, 26, coord_health, size);
	if (engine->player->health == 50)
		draw_ath_texture(engine, 27, coord_health, size);
	if (engine->player->health == 75)
		draw_ath_texture(engine, 28, coord_health, size);
	if (engine->player->health == 100)
		draw_ath_texture(engine, 29, coord_health, size);
}
