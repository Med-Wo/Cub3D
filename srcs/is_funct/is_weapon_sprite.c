/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_weapon_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:58:30 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:49:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_weapon_sprite(t_config *config, t_player *player, int i)
{
	if (config->sprite[i].id_texture == MINI_GUN
		&& player->inventory->mini_gun == false)
		return (true);
	return (false);
}
