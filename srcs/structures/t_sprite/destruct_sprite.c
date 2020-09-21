/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 00:11:19 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 13:06:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des elements de t_sprite avant free
*/

void		destroy_sprite(t_sprite to_destroy)
{
	to_destroy.x = 0;
	to_destroy.y = 0;
	to_destroy.id_texture = 0;
	to_destroy.sprite_dist = 0;
}

/*
** Free de t_sprite
*/

void		free_sprite(t_sprite *to_free)
{
	destroy_sprite(*to_free);
}
