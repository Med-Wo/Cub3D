/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_welcome_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:24:27 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:00:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_welcome_tex
*/

void		destroy_welcome_tex(t_welcome_tex to_destroy)
{
	free(to_destroy.path);
	free(to_destroy.img);
	free(to_destroy.addr);
	to_destroy.width = -1;
	to_destroy.height = -1;
	to_destroy.bits_per_pixel = -1;
	to_destroy.line_length = -1;
	to_destroy.endian = -1;
}

/*
** Free de la structure t_welcome_tex
*/

void		free_welcome_tex(t_img_welc *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
