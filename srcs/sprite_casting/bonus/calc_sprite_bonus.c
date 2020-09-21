/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 19:10:16 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 18:50:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcul de la hauteur pour les sprites d'armes, shields, health et ammo
*/

void		calculate_other_sprite_height(t_sprite_cast *sprite_cast
	, t_config *config, int i)
{
	sprite_cast->v_move_screen = (int)(170
			/ sprite_cast->transform_y);
	if (config->sprite[i].id_texture == BACK_PACK
		|| config->sprite[i].id_texture == LITTLE_MEDKIT)
		sprite_cast->sprite_height = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 3);
	else if (config->sprite[i].id_texture == MEDKIT)
		sprite_cast->sprite_height = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 4);
	else if (config->sprite[i].id_texture == GREEN_SHIELD
		|| config->sprite[i].id_texture == BLUE_SHIELD
		|| config->sprite[i].id_texture == RED_SHIELD)
		sprite_cast->sprite_height = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 3);
	else if (config->sprite[i].id_texture == MINI_GUN)
		sprite_cast->sprite_height = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 4);
	else if (config->sprite[i].id_texture == COCADEMON)
	{
		sprite_cast->v_move_screen = (int)(70
			/ sprite_cast->transform_y);
		sprite_cast->sprite_height = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 1.5);
	}
}

/*
** Calcul de la largeur pour les sprites d'armes, shields, health et ammo
*/

void		calculate_other_sprite_width(t_sprite_cast *sprite_cast
	, t_config *config, int i)
{
	if (config->sprite[i].id_texture == BACK_PACK
		|| config->sprite[i].id_texture == LITTLE_MEDKIT
		|| config->sprite[i].id_texture == MEDKIT)
		sprite_cast->sprite_width = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 3);
	else if (config->sprite[i].id_texture == GREEN_SHIELD
		|| config->sprite[i].id_texture == BLUE_SHIELD
		|| config->sprite[i].id_texture == RED_SHIELD)
		sprite_cast->sprite_width = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 2);
	else if (config->sprite[i].id_texture == MINI_GUN)
		sprite_cast->sprite_width = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y) / 2.3);
	else if (config->sprite[i].id_texture == COCADEMON)
		sprite_cast->sprite_width = (int)fabs(
			(config->resolution.y / sprite_cast->transform_y));
}
