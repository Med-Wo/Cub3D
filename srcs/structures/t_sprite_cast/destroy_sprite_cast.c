/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprite_cast.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 00:05:54 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:32:16 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		destroy_sprite_cast(t_sprite_cast to_destroy)
{
	to_destroy.sprite_x = 0.0f;
	to_destroy.sprite_y = 0.0f;
	to_destroy.transform_x = 0.0f;
	to_destroy.transform_y = 0.0f;
	to_destroy.inv_det = 0;
	to_destroy.sprite_screen_x = 0;
	to_destroy.draw_start_x = 0;
	to_destroy.draw_start_y = 0;
	to_destroy.draw_end_x = 0;
	to_destroy.draw_end_y = 0;
	to_destroy.tex_x = 0;
	to_destroy.tex_y = 0;
	to_destroy.z_buffer = NULL;
	to_destroy.v_move_screen = 0;
}

void		free_sprite_cast(t_sprite_cast *to_free)
{
	destroy_sprite_cast(*to_free);
	free(to_free);
}
