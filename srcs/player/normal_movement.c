/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:43:57 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 10:40:19 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Permet de faire avancer le personnage dans le ray_casting
*/

static void		forward_move(t_player *player, float mov_speed
	, char **world_map)
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;

	pos = player->pos;
	dir = player->dir;
	plane = player->plane;
	if (is_not_wall_sprite(create_vector(pos.x + dir.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x += dir.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x
		, pos.y + dir.y * mov_speed), world_map) == true)
		player->pos.y += dir.y * mov_speed;
}

/*
** Permet de faire reculer le personnage dans le ray_casting
*/

static void		backward_move(t_player *player, float mov_speed
	, char **world_map)
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;

	pos = player->pos;
	dir = player->dir;
	plane = player->plane;
	if (is_not_wall_sprite(create_vector(pos.x - dir.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x -= dir.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x
		, pos.y - dir.y * mov_speed), world_map) == true)
		player->pos.y -= dir.y * mov_speed;
}

/*
** Permet de faire deplacer le personnage sur la gauche dans le ray_casting
*/

static void		left_move(t_player *player, float mov_speed
	, char **world_map)
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;

	pos = player->pos;
	dir = player->dir;
	plane = player->plane;
	if (is_not_wall_sprite(create_vector(pos.x - plane.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x -= plane.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x
		, pos.y - plane.y * mov_speed), world_map) == true)
		player->pos.y -= plane.y * mov_speed;
}

/*
** Permet de faire deplacer le personnage sur la droite dans le ray_casting
*/

static void		right_move(t_player *player, float mov_speed
	, char **world_map)
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;

	pos = player->pos;
	dir = player->dir;
	plane = player->plane;
	if (is_not_wall_sprite(create_vector(pos.x + plane.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x += plane.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x, pos.y + plane.y * mov_speed)
		, world_map) == true)
		player->pos.y += plane.y * mov_speed;
}

/*
** Permet d'effectuer les movements simples du personnage
*/

void			simple_move(t_player *player, t_event *event
	, float mov_speed, char **world_map)
{
	if (event->forward == true)
		forward_move(player, mov_speed, world_map);
	if (event->backward == true)
		backward_move(player, mov_speed, world_map);
	if (event->left == true)
		left_move(player, mov_speed, world_map);
	if (event->right == true)
		right_move(player, mov_speed, world_map);
}
