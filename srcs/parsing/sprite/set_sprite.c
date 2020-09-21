/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:40:53 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 10:58:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Set des reglages du sprites et comptabilisation du nombres de sprites
*/

static void		set_sprite(t_config *config, t_vector index, int id)
{
	config->sprite[config->num_sprites].x = index.x + 0.5f;
	config->sprite[config->num_sprites].y = index.y + 0.5f;
	config->sprite[config->num_sprites].id_texture = id;
	config->num_sprites++;
}

/*
** Check si aucun espace n'est present autour du sprite
** et set des ses reglages
*/

void			check_and_set_sprite(t_config *config, char **map
	, t_vector index)
{
	check_around(map, index);
	if (map[(int)index.y][(int)index.x] == '2')
		set_sprite(config, index, BASIC_SP);
	if (map[(int)index.y][(int)index.x] == '3')
		set_sprite(config, index, BACK_PACK);
	if (map[(int)index.y][(int)index.x] == '4')
		set_sprite(config, index, MEDKIT);
	if (map[(int)index.y][(int)index.x] == '5')
		set_sprite(config, index, GREEN_SHIELD);
	if (map[(int)index.y][(int)index.x] == '6')
		set_sprite(config, index, BLUE_SHIELD);
	if (map[(int)index.y][(int)index.x] == '7')
		set_sprite(config, index, RED_SHIELD);
	if (map[(int)index.y][(int)index.x] == '8')
		set_sprite(config, index, MINI_GUN);
	if (map[(int)index.y][(int)index.x] == '9')
		set_sprite(config, index, COCADEMON);
}
