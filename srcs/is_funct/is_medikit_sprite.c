/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_medikit_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:53:55 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:51:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_medkit_sprite(t_config *config, t_player *player, int i)
{
	if (config->sprite[i].id_texture == MEDKIT && player->health < 100)
		return (true);
	return (false);
}
