/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:35:55 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:36:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_line_texture(char *line, int i)
{
	if ((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			|| (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			|| (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			|| (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			|| (line[i] == 'S' && line[i + 1] == ' '))
		return (true);
	return (false);
}
