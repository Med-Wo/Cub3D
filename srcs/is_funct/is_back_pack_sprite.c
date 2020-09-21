/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_back_pack_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:55:11 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:53:23 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_backpack_sprite(t_config *config, t_player *player, int i)
{
	if (config->sprite[i].id_texture == BACK_PACK
		&& player->inventory->ammo < 25)
		return (true);
	return (false);
}
