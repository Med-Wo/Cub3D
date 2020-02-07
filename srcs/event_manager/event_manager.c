/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:57:49 by mravily           #+#    #+#             */
/*   Updated: 2020/02/06 02:06:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     handle_key_pressed(int key, void *params)
{
	t_appli *appli;

	appli = (t_appli *)params;
	if (key == ESC_KEY)
	 	close_cub(appli);
	if (key == W_KEY)
		appli->player->forward = true;
	if (key == A_KEY)
		appli->player->left = true;
	if (key == S_KEY)
		appli->player->backward = true;
	if (key == D_KEY)
		appli->player->right = true;
	if (key == LEFT_KEY)
		appli->player->rotate_left = true;
	if (key == RIGHT_KEY)
		appli->player->rotate_right = true;
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
}
