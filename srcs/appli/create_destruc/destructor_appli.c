/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor_appli.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 22:41:50 by mravily           #+#    #+#             */
/*   Updated: 2020/05/12 16:40:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_application(t_engine *engine)
{
	mlx_destroy_window(engine->vars->mlx_ptr, engine->vars->win_ptr);
	free(engine);
}
