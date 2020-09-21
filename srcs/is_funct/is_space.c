/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:56:48 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:50:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_space(t_vector index, char **map)
{
	if (map[(int)index.y][(int)index.x] == ' ')
		return (true);
	return (false);
}
