/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:27:00 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 11:09:01 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_inventory		create_inventory(void)
{
	t_inventory		result;

	result.ammo = 0;
	result.mini_gun = false;
	result.slot_1 = true;
	result.slot_2 = false;
	return (result);
}

t_player				create_player(float x, float y
	, t_inventory *inventory)
{
	t_player	result;

	result.inventory = inventory;
	result.health = 100;
	result.shield = 0;
	result.rot_speed = 0.06f;
	result.mov_speed = 0.1f;
	result.start_mov_speed = result.mov_speed;
	result.pos = create_vector(x, y);
	result.start_pos = create_vector(x, y);
	result.dir = create_vector(x, y);
	result.start_dir = create_vector(x, y);
	result.pos_map = create_vector(x, y);
	result.rad_play = 0;
	return (result);
}

t_player				*malloc_player(float x, float y)
{
	t_player		*result;
	t_inventory		*inventory;

	result = (t_player *)malloc(sizeof(t_player));
	if (result == NULL)
		return (NULL);
	inventory = (t_inventory *)malloc(sizeof(t_inventory));
	if (inventory == NULL)
		return (NULL);
	*inventory = create_inventory();
	*result = create_player(x, y, inventory);
	return (result);
}
