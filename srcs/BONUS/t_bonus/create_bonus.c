/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 23:35:11 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:45:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mallocage de la structure t_bonus
*/

t_bonus		*malloc_bonus(t_ray_cast *ray_cast)
{
	t_bonus		*bonus;

	bonus = (t_bonus *)malloc(sizeof(t_bonus));
	if (bonus == NULL)
		return (NULL);
	*bonus = create_bonus(ray_cast);
	return (bonus);
}

/*
** Initialisation des elements de la structure t_bonus
*/

t_bonus		create_bonus(t_ray_cast *ray_cast)
{
	t_bonus		bonus;

	bonus.floor_cast = malloc_floor_cast(ray_cast);
	bonus.mini_map = NULL;
	bonus.img_welc = NULL;
	bonus.helmet = NULL;
	bonus.weapon = NULL;
	return (bonus);
}
