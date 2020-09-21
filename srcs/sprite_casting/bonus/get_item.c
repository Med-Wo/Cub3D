/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:00:01 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 18:10:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		item_green_shield(t_config *config, t_player *player, int i)
{
	if (config->sprite[i].id_texture == GREEN_SHIELD)
	{
		if (player->shield == 0)
		{
			puts("You put on a new green armor with 100 armor points.");
			player->shield = 100;
		}
		else
		{
			puts("You've picked up green armor, it gives you 25 armor points.");
			player->shield += 25;
		}
		if (player->shield > 200)
			player->shield = 200;
	}
}

static void		item_blue_shield(t_config *config, t_player *player, int i)
{
	if (config->sprite[i].id_texture == BLUE_SHIELD)
	{
		puts("You picked up a Blue Shield");
		if (player->shield == 0)
		{
			puts("You put on a new blue armor with 150 armor points.");
			player->shield = 150;
		}
		else
		{
			puts("You've picked up blue armor, it gives you 50 armor points.");
			player->shield += 50;
		}
		if (player->shield > 200)
			player->shield = 200;
	}
}

static void		item_red_shield(t_config *config, t_player *player, int i)
{
	if (config->sprite[i].id_texture == RED_SHIELD)
	{
		if (player->shield == 0)
		{
			puts("You put on a new red armor with 200 armor points.");
			player->shield = 200;
		}
		else
		{
			player->shield += 100;
			puts("You've picked up a red armor, it gives you 50 armor points.");
		}
		if (player->shield > 200)
			player->shield = 200;
	}
}

/*
** Recuperation des items dans le jeu
*/

void			get_item(t_player *player, t_config *config, int i)
{
	if (config->sprite[i].id_texture == MEDKIT)
	{
		player->health += 25;
		puts("You pick up a care kit, and you heal 25 life points");
	}
	if (config->sprite[i].id_texture == BACK_PACK)
	{
		puts("You picked up a backpack with ammunition in it.");
		if (player->inventory->ammo != 25)
			player->inventory->ammo += 5;
		else if ((player->inventory->ammo += 5) > 25)
			player->inventory->ammo = 25;
	}
	if (config->sprite[i].id_texture == MINI_GUN)
	{
		puts("You've picked up a Mini Gun... God bless america.");
		player->inventory->mini_gun = true;
	}
	item_green_shield(config, player, i);
	item_red_shield(config, player, i);
	item_blue_shield(config, player, i);
}
