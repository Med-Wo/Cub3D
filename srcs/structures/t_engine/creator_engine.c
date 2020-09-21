/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 22:35:39 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 17:08:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mallocage de la structure t_engine
*/

t_engine		*malloc_engine(char *title)
{
	t_engine		*engine;

	engine = (t_engine *)malloc(sizeof(t_engine));
	if (engine == NULL)
		return (NULL);
	*engine = create_engine(title);
	return (engine);
}

/*
** Initialisation des elements de la structure t_engine
*/

t_engine		create_engine(char *title)
{
	t_engine	engine;

	engine.vars = malloc_vars();
	engine.image = malloc_image();
	engine.ray_cast = malloc_ray_cast();
	engine.sprite_cast = malloc_sprite_cast();
	engine.config = malloc_config(title);
	engine.player = malloc_player(0, 0);
	engine.event = malloc_event();
	engine.bonus = malloc_bonus(engine.ray_cast);
	return (engine);
}
