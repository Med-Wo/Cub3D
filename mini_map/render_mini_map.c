/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:34:58 by mravily           #+#    #+#             */
/*   Updated: 2020/04/11 23:31:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			render_mini_map(t_engine *engine)
{
	mlx_put_image_to_window(engine->vars->mlx_ptr
		, engine->vars->win_ptr
		, engine->bonus->mini_map->img, 0, 0);
}