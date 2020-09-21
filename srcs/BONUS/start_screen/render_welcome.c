/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_welcome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:01:01 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:07:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			render_welcome(t_engine *engine)
{
	mlx_put_image_to_window(engine->vars->mlx_ptr, engine->vars->win_ptr
		, engine->bonus->img_welc->img, 0, 0);
}
