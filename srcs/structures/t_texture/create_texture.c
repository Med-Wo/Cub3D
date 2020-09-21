/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:10:31 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:29:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des variables de la struct t_texture
** - Pointeur vers l'image
** - Les bitmap de l'image stocker en int
*/

t_texture	create_texture(t_engine *engine, char *path)
{
	t_texture	texture;
	t_config	*config;

	config = engine->config;
	texture.path = path;
	texture.img = NULL;
	texture.color = NULL;
	if (!(texture.img = mlx_xpm_file_to_image(engine->vars->mlx_ptr
		, path, &(texture.width), &(texture.height))))
	{
		error_exit_cub(path
		, "during creation of xpm pointer for the texture, path invalid"
		, "Check if the image is present at this path.");
	}
	texture.color = (int *)mlx_get_data_addr(texture.img
		, &(texture.bits_per_pixel)
		, &(texture.line_length), &(texture.endian));
	return (texture);
}

/*
** Mallocage de la structure t_texture pour les walls
*/

t_texture	*malloc_texture(t_engine *engine, char *path)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	*texture = create_texture(engine, path);
	return (texture);
}
