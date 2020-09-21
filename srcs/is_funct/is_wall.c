/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:46:35 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:50:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_wall(char **map, t_vector index)
{
	if (map[(int)index.y][(int)index.x] == '1')
		return (true);
	return (false);
}
