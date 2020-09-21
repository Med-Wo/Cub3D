/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite_casting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 21:10:45 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 18:48:01 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcul de la hauteur du sprite et de son pixel de depart et de fin sur y
*/

static void			calculate_sprite_height(t_sprite_cast *sprite_cast
	, t_config *config, int i)
{
	if (config->sprite[i].id_texture == BASIC_SP)
	{
		sprite_cast->v_move_screen = (int)(config->texture[SPRITE].height
			/ sprite_cast->transform_y);
		sprite_cast->sprite_height = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y));
	}
	else
		calculate_other_sprite_height(sprite_cast, config, i);
}

/*
** Calcule du pixel de depart et de fin sur l'axe y
*/

static void			calculate_draw_start_y(t_sprite_cast *sprite_cast
	, t_config *config)
{
	sprite_cast->draw_start_y = -sprite_cast->sprite_height / 2
		+ config->resolution.y / 2
		+ sprite_cast->v_move_screen;
	if (sprite_cast->draw_start_y < 0)
		sprite_cast->draw_start_y = 0;
	sprite_cast->draw_end_y = sprite_cast->sprite_height / 2
		+ config->resolution.y / 2
		+ sprite_cast->v_move_screen;
	if (sprite_cast->draw_end_y >= config->resolution.y)
		sprite_cast->draw_end_y = config->resolution.y - 1;
}

/*
** Calcul de la largeur du sprite et de son pixel de depart et de fin sur x
*/

static void			calculate_sprite_width(t_sprite_cast *sprite_cast
	, t_config *config, int i)
{
	if (config->sprite[i].id_texture == BASIC_SP)
		sprite_cast->sprite_width = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y));
	else
		calculate_other_sprite_width(sprite_cast, config, i);
}

/*
** Calcule du pixel de depart et de fin sur l'axe x
*/

static void			calculate_draw_start_x(t_sprite_cast *sprite_cast
	, t_config *config)
{
	sprite_cast->draw_start_x = -sprite_cast->sprite_width / 2
		+ sprite_cast->sprite_screen_x;
	if (sprite_cast->draw_start_x < 0)
		sprite_cast->draw_start_x = 0;
	sprite_cast->draw_end_x = sprite_cast->sprite_width / 2
		+ sprite_cast->sprite_screen_x;
	if (sprite_cast->draw_end_x >= config->resolution.x)
		sprite_cast->draw_end_x = config->resolution.x - 1;
}

/*
** Calcule de la taille a l'ecran du sprite,
** ainsi que ses pixels de depart en x et y
*/

void				calculate_sprite(t_sprite_cast *sprite_cast
	, t_config *config, int i)
{
	calculate_sprite_height(sprite_cast, config, i);
	calculate_draw_start_y(sprite_cast, config);
	calculate_sprite_width(sprite_cast, config, i);
	calculate_draw_start_x(sprite_cast, config);
}
