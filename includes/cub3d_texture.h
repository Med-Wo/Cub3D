/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:42:51 by mravily           #+#    #+#             */
/*   Updated: 2020/02/06 17:46:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_H
# define CUB3D_TEXTURE_H

typedef struct  s_texture
{
	char 		*path;
    void		*img;
    char		*addr;
    int			width;
	int			height;
	int			bits_per_pixel;
	int			endian;
    int			size_line;
}               t_texture;

t_texture		create_texture(char *path);
t_texture		*malloc_texture(char *path);
void			destroy_texture(t_texture to_destroy);
void			free_texture(t_texture *to_free);
t_color			texture_get_color(t_texture *texture, int x, int y);

#endif
