/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:34:25 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:52:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_med_kit(char **map, t_vector index)
{
	if (map[(int)index.y][(int)index.x] == '5')
		return (true);
	return (false);
}

bool		is_back_pack(char **map, t_vector index)
{
	if (map[(int)index.y][(int)index.x] == '3')
		return (true);
	return (false);
}

bool		is_shield(char **map, t_vector index)
{
	if (map[(int)index.y][(int)index.x] == '4')
		return (true);
	return (false);
}
