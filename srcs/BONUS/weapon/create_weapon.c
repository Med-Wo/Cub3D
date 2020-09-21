/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:19:58 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:20:47 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des elements de la structure t_weapon
*/

t_weapon		create_weapon(t_engine *engine)
{
	t_weapon		result;
	int				i;
	char			**path_weapon;

	path_weapon = init_tab_path_weapon_tex();
	i = 0;
	while (i < WEAPON_PART)
	{
		result.weapon[i] = create_weapon_tex(engine, path_weapon[i]);
		i++;
	}
	ft_tab_free(path_weapon);
	result.part_mini_gun = 12;
	return (result);
}

t_weapon		*malloc_weapon(t_engine *engine)
{
	t_weapon	*weapon;

	weapon = (t_weapon *)malloc(sizeof(t_weapon));
	if (weapon == NULL)
		return (NULL);
	*weapon = create_weapon(engine);
	return (weapon);
}
