/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:44:22 by mravily           #+#    #+#             */
/*   Updated: 2020/02/06 17:59:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*malloc_texture(char *path)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	*texture = create_texture(path);
	return (texture);
}

t_texture	create_texture(char *path)
{
	t_texture	texture;

	texture.path = path;
	texture.img = NULL;
	texture.addr = NULL;
	texture.width = 0;
	texture.height =  0;
	texture.img = mlx_xpm_file_to_image(g_vars->mlx_ptr, path, &(texture.width), &(texture.height));
	texture.addr = mlx_get_data_addr(texture.img, &(texture.bits_per_pixel),
						&(texture.size_line), &(texture.endian));
	return (texture);
}

void	destroy_texture(t_texture to_destroy)
{
	free(to_destroy.path);
	free(to_destroy.img);
	free(to_destroy.addr);
	to_destroy.width = 0;
	to_destroy.height = 0;
}

void	free_texture(t_texture *to_free)
{
	destroy_texture (*to_free);
	free(to_free);
}

t_color	texture_get_color(t_texture *texture, int x, int y)
{
	t_color result;
	int pixel_index;
	int rel_y;

	pixel_index = (x + y * texture->width) * 4;
	result = *(t_color *)(&(texture->addr[pixel_index]));
	return (result);
}
