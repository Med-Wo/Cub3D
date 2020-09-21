/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex_x_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:01:54 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 14:48:43 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcule de la valeur initial de tex_x
*/

void		init_tex_y(t_sprite_cast *sprite_cast, t_config *config
	, int draw_start_y, int i)
{
	int		d;

	d = (draw_start_y - sprite_cast->v_move_screen)
		* 256 - config->resolution.y
		* 128 + sprite_cast->sprite_height * 128;
	if (d < 0)
		d = 0;
	sprite_cast->tex_y = (d
		* config->texture[config->sprite[i].id_texture].height)
		/ sprite_cast->sprite_height / 256;
}

/*
** Calcule de la valeur initial de tex_y
*/

void		init_tex_x(t_sprite_cast *sprite_cast, t_config *config
	, int stripe, int i)
{
	sprite_cast->tex_x = (int)(256 * (stripe
		- (-sprite_cast->sprite_width / 2
		+ sprite_cast->sprite_screen_x))
		* config->texture[config->sprite[i].id_texture].width
		/ sprite_cast->sprite_width) / 256;
}
