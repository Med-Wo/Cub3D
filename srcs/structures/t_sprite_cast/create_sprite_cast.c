/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite_cast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 15:38:05 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:39:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des valeurs de t_sprite_cast
*/

t_sprite_cast		create_sprite_cast(void)
{
	t_sprite_cast	result;

	result.sprite_x = 0.0f;
	result.sprite_y = 0.0f;
	result.transform_x = 0.0f;
	result.transform_y = 0.0f;
	result.inv_det = 0;
	result.sprite_screen_x = 0;
	result.draw_start_x = 0;
	result.draw_start_y = 0;
	result.draw_end_x = 0;
	result.draw_end_y = 0;
	result.tex_x = 0;
	result.tex_y = 0;
	result.v_move_screen = 0;
	return (result);
}

/*
** Mallocage de t_sprite_cast
*/

t_sprite_cast		*malloc_sprite_cast(void)
{
	t_sprite_cast	*sprite_cast;

	sprite_cast = (t_sprite_cast *)malloc(sizeof(t_sprite_cast));
	if (sprite_cast == NULL)
		return (NULL);
	*sprite_cast = create_sprite_cast();
	return (sprite_cast);
}
