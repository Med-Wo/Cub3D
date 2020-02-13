/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:57:49 by mravily           #+#    #+#             */
/*   Updated: 2020/02/09 16:30:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     handle_key_pressed(int key, void *params)
{
	t_appli *appli;
	//	map en deux dimension
	char 	**map;
	// variables de stockage
	double		old_dir_x;
	double 		old_plane_x;

	map = appli->config->map;
	appli = (t_appli *)params;
	if (key == ESC_KEY)
	 	close_cub(appli);
	if (key == W_KEY)
	{
		appli->player->forward = true;
		// avancer
		if (appli->player->forward == true)
		{
			// si la prochaine case sur X est libre
			if (map[(int)appli->player->pos.x + (int)appli->player->dir.x * appli->player->mov_speed][(int)appli->player->pos.y] == 0)
			{
				appli->player->pos.x += appli->player->dir.x * appli->player->mov_speed;// on avance sur X
			}

			// si la prochaine case sur Y est libre
			if (map[(int)appli->player->pos.x][(int)appli->player->pos.y + (int)appli->player->dir.y * appli->player->mov_speed] == 0)
			{
				appli->player->pos.y += appli->player->dir.y * appli->player->mov_speed;// on avance sur Y
			}
		}
	}
	if (key == A_KEY)
	{
		appli->player->left = true;
		// Latéral gauche
		if (appli->player->left == true)
		{
			// si le prochain tile sur X est libre on recule sur X
			if (map[(int)appli->player->pos.x - (int)appli->player->plane.x * (int)appli->player->mov_speed][(int)appli->player->pos.y] == 0)
			{
				appli->player->pos.x -= appli->player->plane.x * appli->player->mov_speed;
			}
			// si le prochain tile sur Y est libre on recule sur Y
			if (map[(int)appli->player->pos.x][(int)appli->player->pos.y - (int)appli->player->plane.y * appli->player->mov_speed] == 0)
			{
				appli->player->pos.y -= appli->player->plane.y * appli->player->mov_speed;
			}
		}
	}
	if (key == S_KEY)
	{
		appli->player->backward = true;
		// reculer
		if (appli->player->backward == true)
		{
			if (map[(int)appli->player->pos.x - (int)appli->player->dir.x * appli->player->mov_speed][(int)appli->player->pos.y] == 0)
			{
				appli->player->pos.x -= appli->player->dir.x * appli->player->mov_speed;// on recule sur X
			}
			if (map[(int)appli->player->pos.x][(int)appli->player->pos.y - (int)appli->player->dir.y * appli->player->mov_speed] == 0)
			{
				appli->player->pos.y -= appli->player->dir.y * appli->player->mov_speed;// on recule sur Y
			}
		}
	}
	if (key == D_KEY)
	{
		appli->player->right = true;
		// Latéral droite
		if (appli->player->right == true)
		{
			// si le prochain tile sur X est libre on avance sur X
			if (map[(int)appli->player->pos.x + (int)appli->player->plane.x * appli->player->mov_speed][(int)appli->player->pos.y] == 0)
			{
				appli->player->pos.x += appli->player->plane.x * appli->player->mov_speed;
			}
			// si le prochain tile sur Y est libre on avance sur Y
			if (map[(int)appli->player->pos.x][(int)appli->player->pos.y + (int)appli->player->plane.y * appli->player->mov_speed] == 0)
			{
				appli->player->pos.y += appli->player->plane.y * appli->player->mov_speed;
			}
		}
	}
	if (key == LEFT_KEY)
	{
		appli->player->rotate_left = true;
		appli->player->rot_speed -= 0.2f;
		// tourner
		if (appli->player->rotate_left == true)
		{
			PRINTPOS;
			old_dir_x = appli->player->dir.x;
			appli->player->dir.x = appli->player->dir.x * cos(-appli->player->rot_speed) - appli->player->dir.y * sin(-appli->player->rot_speed);
			appli->player->dir.y = old_dir_x * sin(-appli->player->rot_speed) + appli->player->dir.y * cos(-appli->player->rot_speed);
			old_plane_x = appli->player->plane.x;
			appli->player->plane.x = appli->player->plane.x * cos(-appli->player->rot_speed) - appli->player->plane.y * sin(-appli->player->rot_speed);
			appli->player->plane.y = old_plane_x * sin(-appli->player->rot_speed) + appli->player->plane.y * cos(-appli->player->rot_speed);
		}
	}

	if (key == RIGHT_KEY)
	{
		appli->player->rotate_right = true;
		appli->player->rot_speed = 0.2f;
		// tourner
		if (appli->player->rotate_right == true)
		{
			PRINTPOS;
			old_dir_x = appli->player->dir.x;
			appli->player->dir.x = appli->player->dir.x * cos(-appli->player->rot_speed) - appli->player->dir.y * sin(-appli->player->rot_speed);
			appli->player->dir.y = old_dir_x * sin(-appli->player->rot_speed) + appli->player->dir.y * cos(-appli->player->rot_speed);
			old_plane_x = appli->player->plane.x;
			appli->player->plane.x = appli->player->plane.x * cos(-appli->player->rot_speed) - appli->player->plane.y * sin(-appli->player->rot_speed);
			appli->player->plane.y = old_plane_x * sin(-appli->player->rot_speed) + appli->player->plane.y * cos(-appli->player->rot_speed);
		}
	}


	return (0);
}

int     handle_key_release(int key, void *params)
{
	t_appli *appli;

	appli = (t_appli *)params;
	if (key == ESC_KEY)
	 	close_cub(appli);
	if (key == W_KEY)
		appli->player->forward = false;
	if (key == A_KEY)
		appli->player->left = false;
	if (key == S_KEY)
		appli->player->backward = false;
	if (key == D_KEY)
		appli->player->right = false;
	if (key == LEFT_KEY)
		appli->player->rotate_left = false;
	if (key == RIGHT_KEY)
		appli->player->rotate_right = false;
	return (0);
}
