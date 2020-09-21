/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:49:12 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:54:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Creation des pointeurs et du bitmap de la fenetre
*/

void		create_windows(t_engine *engine)
{
	engine->vars->win_ptr = mlx_new_window(engine->vars->mlx_ptr
		, (int)(engine->config->resolution.x)
		, (int)(engine->config->resolution.y)
		, engine->config->title);
	if (engine->vars->win_ptr == NULL)
		error_exit_cub("engine->vars->win_ptr == NULL"
			, "Problem when creating the window"\
			, "Check your structure");
	init_image(engine, engine->image
		, engine->config->resolution.x
		, engine->config->resolution.y);
}

void		clear_screen(t_engine *engine)
{
	size_t		i;
	size_t		j;

	mlx_clear_window(engine->vars->mlx_ptr, engine->vars->win_ptr);
	i = 0;
	while (i < engine->config->resolution.x)
	{
		j = 0;
		while (j < engine->config->resolution.y)
		{
			my_mlx_pixel_put(engine, i, j, create_color(0, 0, 0));
			j++;
		}
		i++;
	}
}

void		render_screen(t_engine *engine)
{
	mlx_put_image_to_window(engine->vars->mlx_ptr
		, engine->vars->win_ptr, engine->image->img, 0, 0);
}
