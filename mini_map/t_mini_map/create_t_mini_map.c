/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_mini_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 21:39:03 by mravily           #+#    #+#             */
/*   Updated: 2020/04/11 21:39:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_mini_map		*malloc_mini_map(t_engine *engine, int width, int height)
{
	t_mini_map	*mini_map;

	mini_map = (t_mini_map *)malloc(sizeof(t_mini_map));
	if (mini_map == NULL)
		return (NULL);
	*mini_map = create_mini_map(engine, width, height);
	return (mini_map);
}

t_mini_map		create_mini_map(t_engine *engine, int width, int height)
{
	t_mini_map	mini_map;

	/* initialisation de la taille de l'image */
	mini_map.width = width;
	mini_map.height = height;
	/* initialisation du pointeur de la l'image */
	mini_map.img = NULL;
	mini_map.img = mlx_new_image(engine->vars->mlx_ptr, width, height);
	if (mini_map.img == NULL)
		error_exit_cub("mini_map.img == NULL"
			, "Problem when creating the image of minimap"
			, "Check your structure");
	/* initialisation du pointeur des donnee de l'image */
	mini_map.addr = NULL;
	mini_map.addr = mlx_get_data_addr(engine->image->img
		, &(mini_map.bits_per_pixel)
		, &(mini_map.line_length)
		, &(mini_map.endian));
	if (mini_map.addr == NULL)
		error_exit_cub("engine->mini_map->addr == NULL"
			, "Problem when creating data address", "Check your structure");
	return (mini_map);
}