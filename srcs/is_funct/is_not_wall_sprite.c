/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_wall_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 14:07:30 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:51:30 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_not_wall_sprite(t_vector index, char **map)
{
	if (map[(int)index.y][(int)index.x] == '0'
		|| map[(int)index.y][(int)index.x] == '3'
		|| map[(int)index.y][(int)index.x] == '4'
		|| map[(int)index.y][(int)index.x] == '5'
		|| map[(int)index.y][(int)index.x] == '6'
		|| map[(int)index.y][(int)index.x] == '7'
		|| map[(int)index.y][(int)index.x] == '8'
		|| is_cardi_point(index, map) == true)
		return (true);
	return (false);
}
