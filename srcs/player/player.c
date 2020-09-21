/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:02:22 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 10:26:47 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcale de la rotation a droite de la camera
*/

static void		rotate_right(t_player *player, float old_dir_x
	, float rot_speed, float old_plane_x)
{
	player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y
		* sin(rot_speed);
	player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y
		* cos(rot_speed);
	player->plane.x = player->plane.x * cos(rot_speed)
		- player->plane.y * sin(rot_speed);
	player->plane.y = old_plane_x * sin(rot_speed)
		+ player->plane.y * cos(rot_speed);
}

/*
** Calcule de la rotation a gauche de la camera
*/

static void		rotate_left(t_player *player, float old_dir_x
	, float rot_speed, float old_plane_x)
{
	player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y
		* sin(-rot_speed);
	player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y
		* cos(-rot_speed);
	player->plane.x = player->plane.x * cos(-rot_speed)
		- player->plane.y * sin(-rot_speed);
	player->plane.y = old_plane_x * sin(-rot_speed)
		+ player->plane.y * cos(-rot_speed);
}

/*
** Calcul de la rotation dans le raycasting
*/

static void		rotate_in_game(t_player *player, t_event *event)
{
	float		old_dir_x;
	float		old_plane_x;
	float		rot_speed;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	rot_speed = player->rot_speed;
	if (event->rotate_right == true)
		rotate_right(player, old_dir_x, rot_speed, old_plane_x);
	if (event->rotate_left == true)
		rotate_left(player, old_dir_x, rot_speed, old_plane_x);
}

/*
** Calcul du deplacement du joueur dans le raycasting
*/

static void		move_in_game(t_player *player, t_event *event
	, char **world_map)
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
	float		mov_speed;

	pos = player->pos;
	dir = player->dir;
	plane = player->plane;
	mov_speed = player->mov_speed;
	if ((event->forward == true && event->left == true)
		|| (event->forward == true && event->right == true)
		|| (event->backward == true && event->left == true)
		|| (event->backward == true && event->right == true))
		diagonal_movement(player, event, mov_speed, world_map);
	else
		simple_move(player, event, mov_speed, world_map);
}

int				update_player(void *params)
{
	t_engine	*engine;
	char		**world_map;

	engine = (t_engine *)params;
	world_map = engine->config->map;
	rotate_in_game(engine->player, engine->event);
	move_in_game(engine->player, engine->event, world_map);
	render_game(engine);
	return (0);
}
