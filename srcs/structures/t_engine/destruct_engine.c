/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:15:30 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 17:07:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des elements de la structure t_engine
*/

void		destroy_engine(t_engine to_destroy)
{
	free_vars(to_destroy.vars);
	free_image(to_destroy.image);
	free_ray_cast(to_destroy.ray_cast);
	free_sprite_cast(to_destroy.sprite_cast);
	free_player(to_destroy.player);
	free_config(to_destroy.config);
	free_event(to_destroy.event);
}

/*
** Free de la structure t_engine
*/

void		free_engine(t_engine *to_free)
{
	destroy_engine(*to_free);
	free(to_free);
}
