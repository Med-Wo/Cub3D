/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:30:43 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:28:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_parsing_cub(t_config *config, t_player *player)
{
	printf("resolution.x = %f\n", config->resolution.x);
	printf("resolution.y = %f\n", config->resolution.y);
	printf("north = %c\n", config->texture->path[NORTH]);
	printf("south = %c\n", config->texture->path[SOUTH]);
	printf("west = %c\n", config->texture->path[WEST]);
	printf("east = %c\n", config->texture->path[EAST]);
	printf("sprite = %c\n", config->texture->path[SPRITE]);
	printf("floor_texture = %c\n", config->texture->path[FLOOR]);
	printf("rgb_floor = %d, %d, %d\n", config->floor_color.r
		, config->floor_color.g, config->floor_color.b);
	printf("ceiling = %c\n", config->texture->path[CEILING]);
	printf("rgb_ceiling = %d, %d, %d\n", config->ceiling_color.r
		, config->ceiling_color.g, config->ceiling_color.b);
	ft_print_str_tab("map", config->map);
	printf("len_x = %zu\n", config->len_x);
	printf("len_y = %zu\n", config->len_y);
	printf("pos_x = %f\n", player->pos.x);
	printf("pos_y = %f\n", player->pos.y);
	printf("dir_player(%f, %f)\n", player->dir.x, player->dir.y);
}
