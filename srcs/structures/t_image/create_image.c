/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:02:51 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 16:05:23 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image		*malloc_image(void)
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (image == NULL)
		return (NULL);
	*image = create_image();
	return (image);
}

t_image		create_image(void)
{
	t_image		image;

	image.img = NULL;
	image.addr = NULL;
	image.bits_per_pixel = 0;
	image.line_length = 0;
	image.endian = 0;
	return (image);
}

/*
** Initiialisation du pointeur de l'image et de l'adresse des pixels sur l'image
*/

void		init_image(t_engine *engine, t_image *image, int width, int height)
{
	image->img = mlx_new_image(engine->vars->mlx_ptr, width, height);
	if (image->img == NULL)
		error_exit_cub("engine->image->img == NULL"
			, "Problem when creating the image"
			, "Check your structure");
	image->addr = mlx_get_data_addr(image->img
			, &(image->bits_per_pixel)
			, &(image->line_length)
			, &(image->endian));
	if (image->addr == NULL)
		error_exit_cub("engine->image->addr == NULL"
		, "Problem when creating data address", "Check your structure");
}
