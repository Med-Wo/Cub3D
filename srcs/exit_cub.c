/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:40:24 by mravily           #+#    #+#             */
/*   Updated: 2020/05/12 17:23:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_cub(t_engine *engine)
{
	mlx_destroy_image(engine->vars->mlx_ptr, engine->image->img);
	mlx_destroy_window(engine->vars->mlx_ptr, engine->vars->win_ptr);
	exit(0);
}
