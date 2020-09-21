/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:21:53 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 10:49:08 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Permets d'effectuer le mouvement du personnage en diagonal haut gauche
** sans acceleration
*/

static void		upper_left_diagonal(t_player *player, float mov_speed
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
	if (is_not_wall_sprite(create_vector(pos.x - plane.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x -= plane.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x
		, pos.y - plane.y * mov_speed), world_map) == true)
		player->pos.y -= plane.y * mov_speed;
}

/*
** Permets d'effectuer le mouvement du personnage en diagonal haut droite
** sans acceleration
*/

static void		upper_right_diagonal(t_player *player, float mov_speed
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
	if (is_not_wall_sprite(create_vector(pos.x + plane.x * mov_speed
			, pos.y), world_map) == true)
		player->pos.x += plane.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x, pos.y + plane.y * mov_speed)
			, world_map) == true)
		player->pos.y += plane.y * mov_speed;
}

/*
** Permets d'effectuer le mouvement du personnage en diagonal bas gauche
** sans acceleration
*/

static void		lower_left_diagonal(t_player *player, float mov_speed
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
	if (is_not_wall_sprite(create_vector(pos.x - plane.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x -= plane.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x
		, pos.y - plane.y * mov_speed), world_map) == true)
		player->pos.y -= plane.y * mov_speed;
}

/*
** Permets d'effectuer le mouvement du personnage en diagonal bas droite
** sans acceleration
*/

static void		lower_right_diagonal(t_player *player, float mov_speed
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
	if (is_not_wall_sprite(create_vector(pos.x + plane.x * mov_speed
		, pos.y), world_map) == true)
		player->pos.x += plane.x * mov_speed;
	if (is_not_wall_sprite(create_vector(pos.x, pos.y + plane.y * mov_speed)
		, world_map) == true)
		player->pos.y += plane.y * mov_speed;
}

/*
** Permets d'effectuer les deplacements du persoonage en diagonal
*/

void			diagonal_movement(t_player *player, t_event *event
	, float mov_speed, char **world_map)
{
	if (event->forward == true && event->left == true)
		upper_left_diagonal(player, mov_speed, world_map);
	else if (event->forward == true && event->right == true)
		upper_right_diagonal(player, mov_speed, world_map);
	else if (event->backward == true && event->left == true)
		lower_left_diagonal(player, mov_speed, world_map);
	else if (event->backward == true && event->right == true)
		lower_right_diagonal(player, mov_speed, world_map);
}
