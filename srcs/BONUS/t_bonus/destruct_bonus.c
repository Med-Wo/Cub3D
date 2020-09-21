/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 23:38:53 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:21:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des elements de la structure t_bonus
*/

void		destroy_bonus(t_bonus to_destroy)
{
	free_floor_cast(to_destroy.floor_cast);
	free_image(to_destroy.mini_map);
	free_image(to_destroy.img_welc);
	free_helmet(to_destroy.helmet);
	free_weapon(to_destroy.weapon);
}

/*
** Free de la structure t_bonus
*/

void		free_bonus(t_bonus *to_free)
{
	destroy_bonus(*to_free);
	free(to_free);
}
