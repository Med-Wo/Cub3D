/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:11:07 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:41:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**Initialiation des variables de la structure t_sprite
*/

t_sprite		create_sprite(void)
{
	t_sprite	result;

	result.active = true;
	result.x = 0;
	result.y = 0;
	result.id_texture = -1;
	result.sprite_dist = 0.0f;
	return (result);
}

t_sprite		*malloc_sprite(void)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	*sprite = create_sprite();
	return (sprite);
}
