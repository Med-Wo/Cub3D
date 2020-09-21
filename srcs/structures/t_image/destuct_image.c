/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destuct_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:40:56 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:55:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_image
** mise a zero des variables avec free de la structure
*/

void		destroy_image(t_image to_destroy)
{
	free(to_destroy.img);
	free(to_destroy.addr);
	to_destroy.bits_per_pixel = 0;
	to_destroy.line_length = 0;
	to_destroy.endian = 0;
}

/*
** Free de la structure t_image
*/

void		free_image(t_image *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
