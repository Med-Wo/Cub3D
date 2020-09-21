/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruc_img_hmlt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:42:02 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:12:29 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_img_hlmt
*/

void		destroy_img_hlmt(t_img_hlmt to_destroy)
{
	to_destroy.width = -1;
	to_destroy.height = -1;
	free(to_destroy.img);
	free(to_destroy.addr);
	to_destroy.bits_per_pixel = -1;
	to_destroy.line_length = -1;
	to_destroy.endian = -1;
}

/*
** Free de la structure t_img_hlmt
*/

void		free_img_hlmt(t_img_hlmt *to_free)
{
	destroy_img_hlmt(*to_free);
	free(to_free);
}
