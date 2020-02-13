/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:59:58 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 17:44:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 		len_map(t_appli *appli, float *len_pixel_x, float *len_pixel_y)
{
	char 	**map;
	int		x;
	int		y;
	int 	len_x;
	int 	len_y;

	map = appli->config->map;
	x = 0;
	y = 0;
	len_x = 0;
	len_y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			x++;
			if (x > len_x)
				len_x++;
		}
		len_y++;
		y++;
	}
	//printf("len_x = %d\n", len_x);
	//printf("len_y = %d\n", len_y);
	*len_pixel_x = (appli->config->resolution_size.x / len_x);
	*len_pixel_y = (appli->config->resolution_size.y / len_y);
}

void		draw_map(t_appli *appli)
{
	int 		x;
	int 		y;
	float		len_pix_x;
	float		len_pix_y;
	float 		coord_x;
	float 		coord_y;
	char  		**map;
	int 		radius;

	coord_x = 0;
	coord_y = 0;
	y = 0;
	map = appli->config->map;
	len_pix_x = 0;
	len_pix_y = 0;
	len_map(appli, &len_pix_x, &len_pix_y);
	// printf("len_pix_x = %f\n", len_pix_x);
	// printf("len_pix_y = %f\n", len_pix_y);
	// printf("1st_pos.x = %f\n", appli->player->pos_map.x);
	// printf("1st_pos.y = %f\n", appli->player->pos_map.y);
	// puts("");
	radius = radius = (int)len_pix_x / 2;
	appli->player->rad_play = (int)len_pix_x / 2;
	if (appli->event->len_pixel == false)
	{
		appli->player->pos_map.x *= (int)len_pix_x;
		appli->player->pos_map.y *= (int)len_pix_y;
		//appli->event->len_pixel = true;
	}
	// printf("2nd_pos.x = %f\n", appli->player->pos_map.x);
	// printf("2nd_pos.y = %f\n", appli->player->pos_map.y);

	while (map[y])
	{
		x = 0;
		coord_x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
			{
				draw_rectangle(appli, create_vector(coord_x, coord_y), create_vector(len_pix_x, len_pix_y), create_color(255, 0, 0));
				coord_x += len_pix_x;
			}
			else if (map[y][x] == '0')
			{
				draw_rectangle(appli, create_vector(coord_x, coord_y), create_vector(len_pix_x, len_pix_y), create_color(255, 255, 255));
				coord_x += len_pix_x;
			}
			else if (map[y][x] == '2')
			{
				draw_rectangle(appli, create_vector(coord_x, coord_y), create_vector(len_pix_x, len_pix_y), create_color(51, 153, 0));
				coord_x += len_pix_x;
			}
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				draw_rectangle(appli, create_vector(coord_x, coord_y), create_vector(len_pix_x, len_pix_y), create_color(255, 255, 255));
				coord_x += len_pix_x;
			}
			//draw_rectangle(appli, create_vector(coord_x, coord_y), create_vector(2, 10), create_color(0, 0, 0));
			x++;
		}
		y++;
		coord_y += len_pix_y;
		//draw_rectangle(appli, create_vector(coord_x, coord_y), create_vector(10, 2), create_color(0, 0, 0));
	}
	if (appli->event->len_pixel == false)
		{
			draw_circle(appli, create_vector(appli->player->pos_map.x, appli->player->pos_map.y), radius, create_color(0, 0, 255));
			appli->event->len_pixel = true;
		}

}
