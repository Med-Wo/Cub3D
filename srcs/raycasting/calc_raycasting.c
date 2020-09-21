/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 00:33:55 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 19:48:30 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcule de la position du rayon et de sa direction
** et la valeur initial de delta_dist
** camera_x == Coordonnee en X de la camera dans l'espace
** ray_dir == Calcule de la direction du rayon
** map_x et y == Position du joueur sur la map
** delta_dist_x/y = Longueur du rayon d'un côté X ou Y au côté X ou Y suivant
*/

void		calc_ray_dir_and_delta(t_player *player, t_ray_cast *ray_cast
	, int x, float width)
{
	ray_cast->camera_x = 2 * x / (float)width - 1;
	ray_cast->ray_dir.x = player->dir.x + player->plane.x * ray_cast->camera_x;
	ray_cast->ray_dir.y = player->dir.y + player->plane.y * ray_cast->camera_x;
	ray_cast->map_x = (int)player->pos.x;
	ray_cast->map_y = (int)player->pos.y;
	ray_cast->delta_dist.x = fabs(1 / ray_cast->ray_dir.x);
	ray_cast->delta_dist.y = fabs(1 / ray_cast->ray_dir.y);
}

/*
** Calcule de side_dist et de la veleur initial de step
*/

void		calc_step_and_side_dist(t_player *player, t_ray_cast *ray_cast)
{
	if (ray_cast->ray_dir.x < 0)
	{
		ray_cast->step_x = -1;
		ray_cast->side_dist.x = (player->pos.x - ray_cast->map_x)
			* ray_cast->delta_dist.x;
	}
	else
	{
		ray_cast->step_x = 1;
		ray_cast->side_dist.x = (ray_cast->map_x + 1.0 - player->pos.x)
			* ray_cast->delta_dist.x;
	}
	if (ray_cast->ray_dir.y < 0)
	{
		ray_cast->step_y = -1;
		ray_cast->side_dist.y = (player->pos.y - ray_cast->map_y)
			* ray_cast->delta_dist.y;
	}
	else
	{
		ray_cast->step_y = 1;
		ray_cast->side_dist.y = (ray_cast->map_y + 1.0 - player->pos.y)
			* ray_cast->delta_dist.y;
	}
}

/*
** Execution du DDA
*/

void		perform_dda(t_ray_cast *ray_cast, char **world_map)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray_cast->side_dist.x < ray_cast->side_dist.y)
		{
			ray_cast->side_dist.x += ray_cast->delta_dist.x;
			ray_cast->map_x += ray_cast->step_x;
			ray_cast->side = 0;
		}
		else
		{
			ray_cast->side_dist.y += ray_cast->delta_dist.y;
			ray_cast->map_y += ray_cast->step_y;
			ray_cast->side = 1;
		}
		if (world_map[ray_cast->map_y][ray_cast->map_x] == '1')
			hit = 1;
	}
}

/*
** Calcule de la distance perpendiculaire par rapport au mur
** (effet fisheye)
*/

void		calc_perp_wall_dist(t_ray_cast *ray_cast, t_player *player)
{
	if (ray_cast->side == 0)
		ray_cast->perp_wall_dist = (ray_cast->map_x - player->pos.x
			+ (1 - ray_cast->step_x) / 2)
			/ ray_cast->ray_dir.x;
	else
		ray_cast->perp_wall_dist = (ray_cast->map_y - player->pos.y
			+ (1 - ray_cast->step_y) / 2)
			/ ray_cast->ray_dir.y;
	if (ray_cast->perp_wall_dist == 0)
		ray_cast->perp_wall_dist = 0.1;
}

/*
** Calcul de la valeur initial de line_height, draw_start et draw_end
** line_height == Calcule de la hauteur de la line a draw a l'ecran
** draw_start = calc le pixel le plus bas et le plus haut
** pour remplir la bande actuelle
*/

void		calc_line_height_and_draw_point(t_ray_cast *ray_cast, float height)
{
	ray_cast->line_height = (int)(height / ray_cast->perp_wall_dist);
	ray_cast->draw_start = -ray_cast->line_height / 2 + height / 2;
	if (ray_cast->draw_start < 0)
		ray_cast->draw_start = 0;
	ray_cast->draw_end = ray_cast->line_height / 2 + height / 2;
	if (ray_cast->draw_end >= height)
		ray_cast->draw_end = height - 1;
}
