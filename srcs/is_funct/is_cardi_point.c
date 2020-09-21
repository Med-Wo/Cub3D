/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cardi_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:50:33 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:53:16 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_cardi_point(t_vector index, char **map)
{
	if (map[(int)index.y][(int)index.x] == 'N'
		|| map[(int)index.y][(int)index.x] == 'S'
		|| map[(int)index.y][(int)index.x] == 'W'
		|| map[(int)index.y][(int)index.x] == 'E')
		return (true);
	return (false);
}
