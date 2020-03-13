/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:03:48 by mravily           #+#    #+#             */
/*   Updated: 2020/03/12 18:00:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CONFIG_H
# define CUBE3D_CONFIG_H

# include "cub3d_player.h"
# include "cub3d_color.h"

typedef struct	s_config
{
	char		*title;
	t_vector 	resolution;

	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char 		*floor_texture;
	char 		*ceiling_texture;

	char		*sprite_texture;

	t_color		floor;
	t_color		ceiling;

	char		**map;
	int 		len_x;
	int 		len_y;
}				t_config;

t_config	*malloc_config(char *title);
t_config	create_config(char *title);
void		destroy_config(t_config to_destroy);
void		free_config(t_config *to_free);

t_config	*formatter(char *title);



#endif