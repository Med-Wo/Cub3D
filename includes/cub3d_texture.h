/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:42:51 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 11:11:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_H
# define CUB3D_TEXTURE_H

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SPRITE 4
# define FLOOR 5
# define CEILING 6

# include <stdbool.h>

typedef struct	s_texture
{
	char		*path;
	void		*img;
	int			width;
	int			height;
	int			*color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

t_texture		init_texture(void);
void			destroy_texture(t_texture to_destroy);
void			free_texture(t_texture *to_free);
t_color			texture_get_color(t_texture *texture, int x, int y);

#endif
