/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_helmet_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:45:06 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:14:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_helmet_tex
*/

void		destroy_helmet_tex(t_helmet_tex to_destroy)
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
** Free de la structure t_helmet_tex
*/

void		free_helmet_tex(t_helmet_tex *to_free)
{
	destroy_helmet_tex(*to_free);
	free(to_free);
}
