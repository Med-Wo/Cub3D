/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destuct_t_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:28:04 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 11:32:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		destroy_inventory(t_inventory to_destroy)
{
	to_destroy.ammo = 0;
	to_destroy.mini_gun = false;
	to_destroy.slot_1 = true;
	to_destroy.slot_2 = false;
}

static void		free_inventory(t_inventory *to_free)
{
	destroy_inventory(*to_free);
	free(to_free);
}

static void		destroy_player(t_player to_destroy)
{
	free_inventory(to_destroy.inventory);
	to_destroy.health = 0;
	to_destroy.shield = 0;
	to_destroy.rot_speed = 0;
	to_destroy.mov_speed = 0;
	to_destroy.start_mov_speed = 0;
	free_vector(&to_destroy.pos);
	free_vector(&to_destroy.start_pos);
	free_vector(&to_destroy.dir);
	free_vector(&to_destroy.start_dir);
	free_vector(&to_destroy.pos_map);
	to_destroy.rad_play = 0;
}

void			free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}
