/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:13:24 by mravily           #+#    #+#             */
/*   Updated: 2020/02/07 16:50:45 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_appli *appli)
{
	char 		**map; 			// map en deux dimension
	// position de la caméra
	double	 	pos_x;
	double 		pos_y;
	// vecteur de direction
	double 		dir_x;
	double 		dir_y;
	// vecteur du plan de projection
	double 		plane_x;
	double 		plane_y;
	// taille de la projection
	double 		project_w;
	double		project_h;
	// position de départ du tracé de l'écran sur X et Y
	int 		x;
	int 		y;
	// Position de départ et direction du rayon
	double 		camera_x;  		// position de la colonne par rapport au centre de l’écran
	// position de départ du rayon sur X et Y
	double 		ray_pos_x;
	double 		ray_pos_y;
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

	floor = create_color(102, 102, 0);
	ceiling = create_color(0, 0, 204);
	map = appli->config->map;
	pos_x = 2;
	pos_y = 5;

	dir_x = -1;
	dir_y = 0;
	plane_x = 0;
	plane_y = 1;
	project_w = 640;
	project_h = 480;
	x = 0;
	y = 0;

	hit = 0;
	ray_pos_x = pos_x;
	ray_pos_y = pos_y;
	// Tant que la position du tracé est inférieure à la taille de l’écran de projection.
	while (x <= project_w)
	{
		camera_x = (2 * x / (double)project_w) - 1;
		//printf("1st_ray_pos_x = %f\n", ray_pos_x);
		ray_dir_x = dir_x + plane_x * camera_x;
		ray_dir_y = dir_y + plane_y * camera_x;
		map_x = ray_pos_x;
		map_y = ray_pos_y;
		delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
		delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
		//calcule le vecteur de direction et la longueur entre deux segments
		if (ray_dir_x < 0)
		{
			step_x = -1;// vecteur de direction
	 		side_dist_x = (ray_pos_x - map_x) * delta_dist_x;   // distance
		}
		else
		{
			step_x = 1;
	 		side_dist_x = (map_x + 1.0 - ray_pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (ray_pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - ray_pos_y) * delta_dist_y;
		}
		// tant que le rayon ne rencontre pas de mur
		while (hit == 0)
		{
			//Passe à la case suivante sur X ou Y
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;	// agrandis le rayon
				map_x += step_x;				// prochaine case ou case précédente sur X
				side = 0;						// orientation du mur
			}
			else
			{
				side_dist_y += delta_dist_y;	// agrandis le rayon
				map_y += step_y;				// prochaine case ou case précédente sur Y
				side = 1;						// orientation du mur
			}
			// si le rayon rencontre un mur
			if (map[map_x][map_y] > 0)
			{
				hit = 1;// stoppe la boucle
			}
		}
		//printf("map_x = %d\n", map_x);
		// Calcule la distance corrigée pour la projection
		if (side == 0)
		{
			perp_wall_dist = fabs((map_x - ray_pos_x + (1 - step_x) / 2) / (double)ray_dir_x);
		} else
		{
			perp_wall_dist = fabs((map_y - ray_pos_y + (1 - step_y) / 2) / (double)ray_dir_y);
		}
		//printf("perp = %f\n", perp_wall_dist);
		line_height = abs(project_h / perp_wall_dist);
		draw_start = -line_height / 2 + project_h / 2;
		draw_end = line_height / 2 + project_h / 2;
		// limite les zones de tracé à l'écran uniquement
		if (draw_start < 0)
		{
			draw_start = 0;
		}
		if (draw_end >= project_h)
		{
			draw_end = project_h - 1;
		}
		// tracer la colonne
		y = draw_start;
		while (y < draw_end)
		{
			// couleur du pixel pour un mur Nord/Sud
			wall = create_color(242, 242, 242);
			if (side == 1)
			{
				// couleur du pixel pour un mur Est/Ouest
				wall = create_color(204, 204, 204);
			}
			my_mlx_pixel_put(appli, x, y, wall); // trace le pixel
			y++;// incrémente la position Y du prochain pixel à tracer
		}
		// si la fin du mur est < 0 alors on la replace en bas
		if (draw_end < 0)
		{
			draw_end = project_h;
		}
		// trace le sol de la fin du mur au bas de l'écran
		y = draw_end;
		while (y < project_h)
		{
			my_mlx_pixel_put(appli, x, y, floor);// trace le pixel du sol
			my_mlx_pixel_put(appli, x, project_h - y - 1, ceiling);// trace le pixel du plafond
			y++;
		}
		x++ ;
	}
}
