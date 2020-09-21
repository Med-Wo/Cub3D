/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:14:51 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 18:33:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			check_get_item(t_config *config, t_player *player, int i)
{
	if (is_shield_sprite(config, player, i) == true
		|| is_medkit_sprite(config, player, i) == true
		|| is_backpack_sprite(config, player, i) == true
		|| is_weapon_sprite(config, player, i) == true)
	{
		config->sprite[i].active = false;
		get_item(player, config, i);
	}
}

/*
** Set la distance de chaque sprite par rapport au player
*/

static void			set_sprite_dist(t_config *config, t_player *player)
{
	int		i;

	i = 0;
	while (i < config->num_sprites)
	{
		config->sprite[i].sprite_dist = (player->pos.x
		- config->sprite[i].x)
			* (-config->sprite[i].x + player->pos.x)
			+ (player->pos.y - config->sprite[i].y)
			* (player->pos.y - config->sprite[i].y);
		if (config->sprite[i].sprite_dist < 0.16f
			&& config->sprite[i].active == true)
		{
			check_get_item(config, player, i);
		}
		else if (config->sprite[i].sprite_dist < 0.36f
			&& config->sprite[i].id_texture == COCADEMON)
			hit_by_enemy(player);
		i++;
	}
}

/*
** Fonction utiliser pour trier les sprites
*/

static void			short_sprites(t_config *config)
{
	int			i;
	int			j;

	j = config->num_sprites;
	while (j > 0)
	{
		i = 0;
		while (i < config->num_sprites - 1)
		{
			if (config->sprite[i].sprite_dist
				< config->sprite[i + 1].sprite_dist)
				swap_t_sprite(&config->sprite[i], &config->sprite[i + 1]);
			i++;
		}
		j--;
	}
}

/*
** Traduire la position du sprite par rapport a la camera
*/

static void			translate_sprite(t_engine *engine, int i)
{
	engine->sprite_cast->sprite_x = engine->config->sprite[i].x
		- engine->player->pos.x;
	engine->sprite_cast->sprite_y = engine->config->sprite[i].y
		- engine->player->pos.y;
	engine->sprite_cast->inv_det = 1.0 / (engine->player->plane.x
		* engine->player->dir.y
		- engine->player->dir.x
		* engine->player->plane.y);
	engine->sprite_cast->transform_x = engine->sprite_cast->inv_det
		* (engine->player->dir.y
		* engine->sprite_cast->sprite_x
		- engine->player->dir.x
		* engine->sprite_cast->sprite_y);
	engine->sprite_cast->transform_y = engine->sprite_cast->inv_det
		* (-engine->player->plane.y
		* engine->sprite_cast->sprite_x
		+ engine->player->plane.x
		* engine->sprite_cast->sprite_y);
	engine->sprite_cast->sprite_screen_x = (int)(
		(engine->config->resolution.x / 2)
		* (1 + engine->sprite_cast->transform_x
		/ engine->sprite_cast->transform_y));
}

/*
** Algo pour le sprite casting
*/

void				sprite_casting(t_engine *engine)
{
	int		i;

	set_sprite_dist(engine->config, engine->player);
	short_sprites(engine->config);
	i = 0;
	while (i < engine->config->num_sprites)
	{
		translate_sprite(engine, i);
		calculate_sprite(engine->sprite_cast, engine->config, i);
		draw_sprite(engine, i);
		i++;
	}
}
