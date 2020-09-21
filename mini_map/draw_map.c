/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:50:20 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 19:20:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 		draw_tile_mini_map(t_engine *engine, int *val_int, float *val_float, char **map)
{
	if (map[val_int[1]][val_int[0]] == '1')
	{
		draw_rectangle_on_mini_map(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(255, 0, 0));
		val_float[2] += val_float[0];
	}
	else if (map[val_int[1]][val_int[0]] == ' ')
	{
		val_float[2] += val_float[0];
	}
	else if (map[val_int[1]][val_int[0]] == '0')
	{
		draw_rectangle_on_mini_map(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(255, 255, 255));
		val_float[2] += val_float[0];
	}
	else if (map[val_int[1]][val_int[0]] == '2')
	{
		draw_rectangle_on_mini_map(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(0, 255, 0));
		val_float[2] += val_float[0];
	}
	else if (is_cardi_point(create_vector(val_int[0], val_int[1]), map) == true)
	{
		draw_rectangle_on_mini_map(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(255, 255, 255));
		val_float[2] += val_float[0];
	}
	
}

void 		draw_tile_map(t_engine *engine, int *val_int, float *val_float, char **map)
{
	if (map[val_int[1]][val_int[0]] == '1')
	{
		draw_rectangle(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(255, 0, 0));
		val_float[2] += val_float[0];
	}
	else if (map[val_int[1]][val_int[0]] == ' ')
	{
		val_float[2] += val_float[0];
	}
	else if (map[val_int[1]][val_int[0]] == '0')
	{
		draw_rectangle(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(255, 255, 255));
		val_float[2] += val_float[0];
	}
	else if (map[val_int[1]][val_int[0]] == '2')
	{
		draw_rectangle(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(0, 255, 0));
		val_float[2] += val_float[0];
	}
	else if (is_cardi_point(create_vector(val_int[0], val_int[1]), map) == true)
	{
		draw_rectangle(engine, create_vector(val_float[2], val_float[3]),
		create_vector(val_float[0], val_float[1]), create_color(255, 255, 255));
		val_float[2] += val_float[0];
	}
	
}

/* ******************* */
/* val_int[0] = x      */
/* val_int[1] = y      */
/* val_int[2] = radius */
/* ******************* */

/* ************************* */
/* val_float[0] = len_pix_x  */
/* val_float[1] = len_pix_y  */
/* val_float[2] = coord_x    */
/* val_float[3] = coord_y    */
/* ************************* */

void		draw_map(t_engine *engine, int call)
{
	int 		val_int[3];
	float		val_float[4];
	char  		**map;


	val_float[2] = 0;
	val_float[3] = 0;
	map = engine->config->map;
	/* Calcul de la taille d'une tile pour l'ecran complet */
	if (call == 1)
	{
		val_float[0] = (engine->config->resolution.x / engine->config->len_x);
		val_float[1] = (engine->config->resolution.y / engine->config->len_y);
	}
	/* Calcul de la taille d'une tile pour la mini map */
	else
	{
		
		val_float[0] = (engine->bonus->mini_map->width / engine->config->len_x);
		val_float[1] = (engine->bonus->mini_map->height / engine->config->len_y);
	}
	/* Calcul de la taille du radius du player */
	val_int[2] = (int)val_float[0] / 2;
	val_int[1] = 0;
	while (map[val_int[1]])
	{
		val_int[0] = 0;
		val_float[2] = 0;
		while (map[val_int[1]][val_int[0]] != '\0')
		{
			if (call == 1)
				draw_tile_map(engine, val_int, val_float, map);
			else
				draw_tile_mini_map(engine, val_int, val_float, map);
			val_int[0]++;
		}
		val_int[1]++;
		val_float[3] += val_float[1];
	}
}