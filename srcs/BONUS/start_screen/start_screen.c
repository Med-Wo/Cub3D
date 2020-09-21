/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:01:31 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:06:13 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		start_screen(t_engine *engine)
{
	t_welcome_tex		*welcome;
	t_vector			coord;
	t_vector			size;

	coord = create_vector(0, engine->config->resolution.y / 2.5);
	size = create_vector(engine->config->resolution.x
		, engine->config->resolution.y / 5);
	welcome = malloc_welcome_tex(engine, "./textures/xpm/WELCOME.xpm");
	draw_welcome_texture(engine, welcome, coord, size);
}

void		game_over_screen(t_engine *engine)
{
	t_welcome_tex		*welcome;
	t_vector			coord;
	t_vector			size;

	coord = create_vector(0, engine->config->resolution.y / 2.5);
	size = create_vector(engine->config->resolution.x
		, engine->config->resolution.y / 5);
	welcome = malloc_welcome_tex(engine, "./textures/xpm/GAME_OVER.xpm");
	draw_welcome_texture(engine, welcome, coord, size);
}
