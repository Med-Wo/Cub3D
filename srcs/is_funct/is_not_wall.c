/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:48:59 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:52:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_not_wall(t_vector index, char **map)
{
	if (map[(int)index.y][(int)index.x] == '0'
		|| map[(int)index.y][(int)index.x] == '2'
		|| is_cardi_point(index, map) == true)
		return (true);
	return (false);
}
