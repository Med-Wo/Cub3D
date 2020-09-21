/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_cast.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:37:45 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 14:04:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_SPRITE_CAST_H
# define CUB3D_SPRITE_CAST_H

# include "cub3d_vector.h"
# include "cub3d_config.h"

# define BASIC_SP 4
# define BACK_PACK 7
# define LITTLE_MEDKIT 8
# define MEDKIT 9
# define GREEN_SHIELD 10
# define BLUE_SHIELD 11
# define RED_SHIELD 12
# define MINI_GUN 13
# define FUCK 14
# define COCADEMON 15

typedef struct	s_sprite
{
	bool		active;
	float		x;
	float		y;
	int			id_texture;
	float		sprite_dist;
}				t_sprite;

typedef struct	s_sprite_cast
{
	float		sprite_x;
	float		sprite_y;

	float		transform_x;
	float		transform_y;

	float		inv_det;
	int			sprite_width;
	int			sprite_height;
	int			sprite_screen_x;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			tex_x;
	int			tex_y;
	float		*z_buffer;
	int			v_move_screen;
}				t_sprite_cast;

t_sprite_cast	*malloc_sprite_cast();
t_sprite_cast	create_sprite_cast();
void			destroy_sprite_cast(t_sprite_cast to_destroy);
void			free_sprite_cast(t_sprite_cast *to_free);
t_sprite		create_sprite(void);
t_sprite		*malloc_sprite(void);
void			destroy_sprite(t_sprite to_destroy);
void			free_sprite(t_sprite *to_free);
void			swap_t_sprite(t_sprite *a, t_sprite *b);

#endif
