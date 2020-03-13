/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:57:48 by mravily           #+#    #+#             */
/*   Updated: 2020/03/12 15:27:49 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	main(int argc, char **argv)
{
	t_config 	*config;
	t_appli 	appli;

	config = malloc_config("Cub3D (c)");
	appli.config = config;

	pre_check_file(argc, argv);
	parsing_cub(argv[1], config);
	// printf("resolution.x = %f\n", config->resolution.x);
	// printf("resolution.y = %f\n", config->resolution.y);
	// printf("north = %s\n", config->north_texture);
	// printf("south = %s\n", config->south_texture);
	// printf("west = %s\n", config->west_texture);
	// printf("east = %s\n", config->east_texture);
	// printf("sprite = %s\n", config->sprite_texture);
	// printf("floor_texture = %s\n", config->floor_texture);
	// printf("rgb_floor = %d, %d, %d\n", config->floor.r, config->floor.g, config->floor.b);
	// printf("ceiling = %s\n", config->ceiling_texture);
	// printf("rgb_ceiling = %d, %d, %d\n", config->ceiling.r, config->ceiling.g, config->ceiling.b);
	// ft_print_str_tab("map", config->map);
	// printf("len_x = %d\n", config->len_x);
	return (0);
}
