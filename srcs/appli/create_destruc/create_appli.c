/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_appli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:31:06 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:55:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** initialisation de la minilibx et des connexions avec le systeme graphique
*/

void		open_appli(t_engine *engine)
{
	engine->vars->mlx_ptr = mlx_init();
	if (engine->vars->mlx_ptr == NULL)
		error_exit_cub("engine->vars->mlx_ptr == NULL"
			, "Problem when launching the MLX", "Check your structure");
	create_windows(engine);
}

void		resize_appli(t_engine *engine)
{
	mlx_destroy_window(engine->vars->mlx_ptr, engine->vars->win_ptr);
	mlx_destroy_image(engine->vars->mlx_ptr, engine->image->img);
	create_windows(engine);
}

void		render_appli(t_engine *engine)
{
	mlx_put_image_to_window(engine->vars->mlx_ptr
		, engine->vars->win_ptr, engine->image->img, 0, 0);
}

int			run_appli(t_engine *engine)
{
	mlx_loop(engine->vars->mlx_ptr);
	return (0);
}
