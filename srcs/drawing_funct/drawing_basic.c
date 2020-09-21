/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:37:04 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 14:50:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_engine *engine, int x, int y, t_color color)
{
	char	*dst;

	if (x < 0 || x >= engine->config->resolution.x
		|| y < 0 || y >= engine->config->resolution.y)
		return ;
	dst = engine->image->addr + (y * engine->image->line_length
		+ x * (engine->image->bits_per_pixel / 8));
	*(t_color *)dst = color;
}
