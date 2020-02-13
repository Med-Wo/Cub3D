/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:02:06 by mravily           #+#    #+#             */
/*   Updated: 2020/02/08 18:24:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include "cub3d_vector.h"
# include "cub3d_event.h"

typedef struct		s_player
{
	t_vector		pos;
	t_vector 		pos_map;
	t_vector	 	dir;
	t_vector 	 	test;
	int 		 	rad_play;
	float	 		dir_angle;

	t_vector 		plane;

	int 			rot_speed;
	int 		 	mov_speed;

	enum e_bool 	forward;
	enum e_bool 	backward;
	enum e_bool		left;
	enum e_bool 	right;
	enum e_bool 	rotate_left;
	enum e_bool	 	rotate_right;
}					t_player;

t_player	*malloc_player(float x, float y);
t_player	create_player(float x, float y);
void		destroy_player(t_player to_destroy);
void		free_player(t_player *to_free);
float		degree_to_radiant(float degree);

#endif
