/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:03:48 by mravily           #+#    #+#             */
/*   Updated: 2020/05/28 12:37:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONFIG_H
# define CUB3D_CONFIG_H

# include "cub3d_color.h"
# include "cub3d_vector.h"
# include "cub3d_texture.h"
# include "cub3d_sprite_cast.h"

# include <stdlib.h>
# include <stdbool.h>

# define NB_TEX 16
# define NB_SP 15

typedef enum	e_way
{
	null = 0,
	path = 1,
	rgb = 2
}				t_way;

typedef struct	s_config
{
	char		*title;
	t_vector	resolution;
	
	t_texture	texture[NB_TEX];
	t_sprite	sprite[15];

	bool		sprite_bonus;
	bool		save;
	int			num_sprites;
	int			*sprite_order;

	t_color		floor_color;
	t_color		ceiling_color;

	t_way		floor_w;
	t_way		ceiling_w;

	int			*wall_color;
	int			*sprite_color;
	int			*floor_color_tex;
	int			*ceiling_color_tex;

	int			wall_tex_x;
	int			wall_tex_y;

	float		step;
	float		tex_pos;

	char		**map;
	size_t		len_x;
	size_t		len_y;
	int			len_pix_x;
	int			len_pix_y;
}				t_config;

t_config		*malloc_config(char *title);
t_config		create_config(char *title);
void			destroy_config(t_config to_destroy);
void			free_config(t_config *to_free);
void			free_map(char **tab);

#endif
