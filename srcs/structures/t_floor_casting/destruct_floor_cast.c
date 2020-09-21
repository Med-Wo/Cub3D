/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_floor_cast.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:32:10 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 16:06:29 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des variables de la struct avant free
*/

void		destroy_floor_cast(t_floor_cast to_destroy)
{
	to_destroy.floor_tex_x = 0;
	to_destroy.floor_tex_y = 0;
	to_destroy.weight = 0;
	to_destroy.current_floor_x = 0;
	to_destroy.current_floor_y = 0;
	to_destroy.floor_tex_x = 0;
	to_destroy.floor_tex_y = 0;
	to_destroy.dist_wall = 0;
	to_destroy.dist_player = 0;
	to_destroy.current_floor_y = 0;
}

/*
** Free de la structure envoyer en parametre
*/

void		free_floor_cast(t_floor_cast *to_free)
{
	destroy_floor_cast(*to_free);
	free(to_free);
}
