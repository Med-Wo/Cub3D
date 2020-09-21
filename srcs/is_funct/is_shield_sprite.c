/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shield_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:51:03 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:51:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_shield_sprite(t_config *config, t_player *player, int i)
{
	if ((config->sprite[i].id_texture == GREEN_SHIELD
		&& player->shield < 200)
		|| (config->sprite[i].id_texture == BLUE_SHIELD
		&& player->shield < 200)
		|| (config->sprite[i].id_texture == RED_SHIELD
		&& player->shield < 200))
		return (true);
	return (false);
}
