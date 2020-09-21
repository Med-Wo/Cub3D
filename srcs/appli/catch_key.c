/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:33:44 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 14:47:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			appli_key_hook(t_engine *engine, int event
	, int (*funct)(int, void *), void *param)
{
	mlx_hook(engine->vars->win_ptr, event, 0L, funct, param);
}

void			application_add_exit_control(t_engine *engine, int event
	, int (*funct)(void))
{
	mlx_hook(engine->vars->win_ptr, event, 0L, funct, (void*)0);
}

void			appli_update(t_engine *engine, int (*funct)(void *)
	, void *param)
{
	mlx_loop_hook(engine->vars->mlx_ptr, funct, param);
}

/*
** Reset la direction du player apres fermeture du screen de demarage
*/

void			re_set_dir_player(int key, t_player *player, t_event *event)
{
	if (key == RTN_KEY && event->start == false)
	{
		event->start = true;
		event->rotate_left = false;
		player->dir = player->start_dir;
		player->plane = player->start_plane;
		player->pos = player->start_pos;
	}
}
