/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:36:40 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:36:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_line_floor_ceiling(char *line, int i)
{
	if ((line[i] == 'F' && line[i + 1] == ' ')
			|| (line[i] == 'C' && line[i + 1] == ' '))
		return (true);
	return (false);
}
