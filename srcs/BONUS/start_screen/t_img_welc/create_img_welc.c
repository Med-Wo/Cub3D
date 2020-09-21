/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_welc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:14:03 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:04:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mallocage de l'image pour le start screen
*/

t_img_welc		*malloc_img_welc(t_engine *engine, int width, int height)
{
	t_img_welc	*img_welc;

	img_welc = (t_img_welc *)malloc(sizeof(t_img_welc));
	if (img_welc == NULL)
		return (NULL);
	*img_welc = create_img_welc(engine, width, height);
	return (img_welc);
}

/*
** Creation des pointeurs et bitmap de l'image pour le start screen
*/

t_img_welc		create_img_welc(t_engine *engine, int width, int height)
{
	t_img_welc	img_welc;

	img_welc.width = width;
	img_welc.height = height;
	img_welc.img = NULL;
	img_welc.img = mlx_new_image(engine->vars->mlx_ptr, width, height);
	if (img_welc.img == NULL)
		error_exit_cub("img_welc.img == NULL"
			, "Problem when creating the image of start_screen"
			, "Check your structure");
	img_welc.addr = NULL;
	img_welc.addr = mlx_get_data_addr(engine->image->img
		, &(img_welc.bits_per_pixel)
		, &(img_welc.line_length)
		, &(img_welc.endian));
	if (img_welc.addr == NULL)
		error_exit_cub("engine->img_welc->addr == NULL"
			, "Problem when creating data address", "Check your structure");
	return (img_welc);
}
