/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:22:16 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:50:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_sprite(char **map, t_vector index, char *list_sprite)
{
	if (ft_strcmp_c(list_sprite, map[(int)index.y][(int)index.x]) == true)
		return (true);
	return (false);
}
