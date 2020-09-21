/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:51:26 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 10:56:20 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calculate_texture(t_ray_cast *ray_cast, t_player *player
	, t_config *config, float height)
{
	if (ray_cast->side == 0)
		ray_cast->wall_x = player->pos.y + ray_cast->perp_wall_dist
			* ray_cast->ray_dir.y;
	else
		ray_cast->wall_x = player->pos.x + ray_cast->perp_wall_dist
			* ray_cast->ray_dir.x;
	ray_cast->wall_x -= floor((ray_cast->wall_x));
	config->wall_tex_x = (int)(ray_cast->wall_x
		* config->texture[NORTH].height);
	if (ray_cast->side == 0 && ray_cast->ray_dir.x > 0)
		config->wall_tex_x = config->texture[NORTH].width
			- config->wall_tex_x - 1;
	if (ray_cast->side == 1 && ray_cast->ray_dir.x < 0)
		config->wall_tex_x = config->texture[NORTH].width
			- config->wall_tex_x - 1;
	config->step = 1.0 * config->texture[NORTH].height
		/ ray_cast->line_height;
	config->tex_pos = (ray_cast->draw_start - height / 2
		+ ray_cast->line_height / 2) * config->step;
}

void		calculate_color(t_ray_cast *ray_cast, t_player *player
	, t_config *config)
{
	if (ray_cast->side == 1 && (ray_cast->map_y > player->pos.y))
		config->wall_color = config->texture[SOUTH].color;
	else if (ray_cast->side == 1 && (ray_cast->map_y < player->pos.y))
		config->wall_color = config->texture[NORTH].color;
	else if (ray_cast->side == 0 && (ray_cast->map_x > player->pos.x))
		config->wall_color = config->texture[EAST].color;
	else
		config->wall_color = config->texture[WEST].color;
	if (config->texture[CEILING].path != NULL)
		config->ceiling_color_tex = config->texture[CEILING].color;
	if (config->texture[FLOOR].path != NULL)
		config->floor_color_tex = config->texture[FLOOR].color;
}
