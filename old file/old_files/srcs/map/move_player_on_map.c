/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_on_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 02:25:51 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 14:31:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_char()
{

}

static void		move_player_w(t_appli *appli, int *value, float len_pix_y
	, float len_pix_x)
{
	char **map;

	map = appli->config->map;
	value[4] = ((appli->player->pos_map.y - (value[1])) / len_pix_y);
	if (map[value[4]][value[3]] == '0' || map[value[4]][value[3]] == 'N'
	|| map[value[4]][value[3]] == 'S' || map[value[4]][value[3]] == 'W'
	|| map[value[4]][value[3]] == 'E')
		appli->player->pos_map.y -= value[2];
	else
		value[4] = ((appli->player->pos_map.y + (value[1]))
		/ len_pix_x);
}

static void		move_player_s(t_appli *appli, int *value, float len_pix_y
	, float len_pix_x)
{
	char **map;

	map = appli->config->map;
	value[4] = ((appli->player->pos_map.y + (value[1])) / len_pix_y);
	if (map[value[4]][value[3]] == '0' || map[value[4]][value[3]] == 'N' ||
	map[value[4]][value[3]] == 'S' || map[value[4]][value[3]] == 'W'
	|| map[value[4]][value[3]] == 'E')
		appli->player->pos_map.y += value[2];
	else
		value[4] = ((appli->player->pos_map.y - (value[1])) / len_pix_x);
}

static void		move_player_a(t_appli *appli, int *value, float len_pix_y
	, float len_pix_x)
{
	char **map;

	map = appli->config->map;
	value[3] = ((appli->player->pos_map.x - (value[1])) / len_pix_x);
	if (map[value[4]][value[3]] == '0' || map[value[4]][value[3]] == 'N'
	|| map[value[4]][value[3]] == 'S' || map[value[4]][value[3]] == 'W'
	|| map[value[4]][value[3]] == 'E')
		appli->player->pos_map.x -= value[2];
	else
		value[3] = ((appli->player->pos_map.x + (value[1]))
		/ len_pix_x);
}

static void		move_player_d(t_appli *appli, int *value, float len_pix_y
	, float len_pix_x)
{
	char **map;

	map = appli->config->map;
	value[3] = ((appli->player->pos_map.x + (value[1])) / len_pix_x);
	if (map[value[4]][value[3]] == '0' || map[value[4]][value[3]] == 'N'
	|| map[value[4]][value[3]] == 'S' || map[value[4]][value[3]] == 'W'
	|| map[value[4]][value[3]] == 'E')
		appli->player->pos_map.x += value[2];
	else
		value[3] = ((appli->player->pos_map.x - (value[1])) / len_pix_x);
}

/*
**     value[0] = radius
**     value[1] = limit_rad
**     value[2] = speed
**     value[3] = x
**     value[4] = y
*/

void			move_player_on_map(int key, t_appli *appli)
{
	int		value[5];
	float	len_pix_x;
	float	len_pix_y;
	char	**map;

	map = appli->config->map;
	len_map(appli, &len_pix_x, &len_pix_y);
	value[0] = (int)len_pix_x / 2;
	value[1] = value[0] - 0.5;
	value[2] = 3;
	value[3] = (appli->player->pos_map.x / len_pix_x);
	value[4] = (appli->player->pos_map.y / len_pix_y);
	if (appli->player->pos_map.x < 0
	|| appli->player->pos_map.x >= appli->config->resolution_size.x
	|| appli->player->pos_map.y < 0
	|| appli->player->pos_map.y >= appli->config->resolution_size.y
	|| appli->event->map == false)
		return ;
	destroy_n_birth(appli);
	if (appli->event->map == true)
		draw_map(appli);
	if (key == W_KEY)
		move_player_w(appli, value, len_pix_y, len_pix_x);
	if (key == S_KEY)
		move_player_s(appli, value, len_pix_y, len_pix_x);
	if (key == A_KEY)
		move_player_a(appli, value, len_pix_y, len_pix_x);
	if (key == D_KEY)
		move_player_d(appli, value, len_pix_y, len_pix_x);
	draw_circle(appli, create_vector(appli->player->pos_map.x,
		appli->player->pos_map.y), value[0], create_color(0, 0, 255));
	// plot_line(&appli, create_vector(appli->player->pos_map.x,
	// 	appli->player->pos_map.y), appli->player->dir,
	// 	create_color(0, 0, 255));
	// puts("");
	// printf("pos.x = %f - speed[%d]\n", appli->player->pos_map.x, 3);
	// printf("pos.y = %f - speed[%d]\n", appli->player->pos_map.y, 3);
	// printf("pos.x = %d\n", value[3]);
	// printf("pos.y = %d\n", value[4]);
	// puts("");
}
