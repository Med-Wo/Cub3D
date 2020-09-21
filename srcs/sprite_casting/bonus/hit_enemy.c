/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:12:29 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 18:48:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		hit_by_enemy(t_player *player)
{
	wait_time(150);
	if (player->shield == 0)
	{
		puts("Beware it's too hot near the Cocademon");
		puts("You lose 25 points of life.");
		player->health -= 25;
	}
	if (player->shield != 0)
	{
		puts("Beware it's too hot near the Cocademon");
		puts("you lose 25 points of shield.");
		player->shield -= 25;
	}
}
