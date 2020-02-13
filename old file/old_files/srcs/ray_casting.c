/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:13:24 by mravily           #+#    #+#             */
/*   Updated: 2020/02/10 15:50:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moove_player(t_appli *appli)
{

}

void	render(t_appli *appli)
{
	char 		**map; 			// map en deux dimension
	// position de la caméra
	double 		pos_x;
	double 		pos_y;
	// vecteur de direction
	int 		dir_x;
	int 		dir_y;
	// vecteur du plan de projection
	double 		plane_x;
	double 		plane_y;
	// taille de la projection
	int 		width;
	int 		height;
	// position de départ du tracé de l'écran sur X et Y
	int 		x;
	int 		y;
	// Position de départ et direction du rayon
	double 		camera_x;  		// position de la colonne par rapport au centre de l’écran
	// position de départ du rayon sur X et Y

	// direction du rayon sur X
	double		ray_dir_x;
	double 		ray_dir_y;

	int 		map_x;
	int 		map_y; 			// sur quelle case est la caméra
	// longueur du rayon
	double 		side_dist_x;
	double		side_dist_y;
	// longueur du rayon entre chaque intersection
	double	 	delta_dist_x;
	double 		delta_dist_y;
	// direction du vecteur sur X et Y (+1 ou -1)
	int 		step_x;
	int			step_y;
	int 		hit; 			// le rayon touche un mur ou pas
	int 		side; 			// quelle orientation à le mur (nord/sud ou est/ouest) dans la map
	double 		perp_wall_dist; // distance corrigée du rayon

	int 		line_height; 	//Calcule la hauteur de la ligne à tracer
	//Calcule les pixels max haut et max bas de la colonne à tracer
	int 		draw_start;
	int 		draw_end;

	t_color 	wall;
	t_color 	floor;
	t_color 	ceiling;

	pos_x = appli->player->pos.x;
	pos_y = appli->player->pos.y;
	map = appli->config->map;
	floor = create_color(102, 102, 0);
	ceiling = create_color(0, 0, 204);
	x = 0;
	width = appli->config->resolution_size.x;
	height = appli->config->resolution_size.y;
	while (x < width)
	{
		camera_x = 2 * x / (double)width - 1;
		ray_dir_x = appli->player->dir.x + appli->player->plane.x * camera_x;
		ray_dir_y = appli->player->dir.y + appli->player->plane.y * camera_x;
		map_x = (int)pos_x;
		map_y = (int)pos_y;
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0f - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0f - pos_y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map[map_x][map_y] > 0)
				hit = 0;
		}
		if (side == 0)
			perp_wall_dist = (map_x - pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - pos_y + (1 - step_y) / 2) / ray_dir_y;
		line_height = ((int)height / (int)perp_wall_dist);
		draw_start = -line_height / 2 + height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + height / 2;
		if (draw_end >= height)
			draw_end = height - 1;
		y = draw_start;
		while (y < draw_end)
		{
			wall = create_color(242, 242, 242); // couleur du pixel pour un mur Nord/Sud
			if (side == 1)
				wall = create_color(204, 204, 204); // couleur du pixel pour un mur Est/Ouest
			my_mlx_pixel_put(appli, x, y, wall);  // trace le pixel
			y++;   // incrémente la position Y du prochain pixel à tracer
		}
		// si la fin du mur est < 0 alors on la replace en bas
		if (draw_end < 0)
		{
			draw_end = height;
		}
		//trace le sol de la fin du mur au bas de l'écran
		y=draw_end;
		while (y < height)
		{
			my_mlx_pixel_put(appli, x, y, floor); // trace le pixel du sol
			my_mlx_pixel_put(appli, x, height - y - 1, ceiling); // trace le pixel du plafond
			y++;
		}
		x++;
	}

}
