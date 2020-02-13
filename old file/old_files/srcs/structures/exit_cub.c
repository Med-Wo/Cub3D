/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:40:24 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 18:41:13 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_cub(t_appli *appli)
{
	mlx_destroy_image(appli->vars->mlx_ptr, appli->data->img);
	mlx_destroy_window(appli->vars->mlx_ptr, appli->vars->win_ptr);
	exit(0);
}

void	destroy_n_birth(t_appli *appli)
{
	mlx_destroy_image(appli->vars->mlx_ptr, appli->data->img);
	appli->data->img = mlx_new_image(appli->vars->mlx_ptr,
		appli->config->resolution_size.x,
		appli->config->resolution_size.y);
	appli->data->addr = mlx_get_data_addr(appli->data->img,
		&appli->data->bits_per_pixel, &appli->data->line_length,
		&appli->data->endian);
}
