/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:02:06 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 11:33:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include "cub3d_vector.h"

# include <stdbool.h>

typedef struct		s_inventory
{
	int				ammo;
	bool			mini_gun;
	bool			slot_1;
	bool			slot_2;
}					t_inventory;

typedef struct		s_player
{
	unsigned int	health;
	unsigned int	shield;
	t_inventory		*inventory;
	float			rot_speed;
	float			mov_speed;
	float			start_mov_speed;
	float			old_dir_x;
	float			old_plane_x;
	t_vector		pos;
	t_vector		start_pos;
	t_vector		pos_map;
	t_vector		dir;
	t_vector		plane;
	t_vector		start_dir;
	t_vector		start_plane;
	int				rad_play;
}					t_player;

t_player			*malloc_player(float x, float y);
t_player			create_player(float x, float y
	, t_inventory *inventory);
void				free_player(t_player *to_free);
int					update_player(void *params);
float				degree_to_radiant(float degree);
t_vector			calc_rotate_vector(float cardi_p, float len_line);
t_vector			calc_axis(float cardi_p, float len_line);

#endif
