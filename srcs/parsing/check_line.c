/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:47:08 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:39:42 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		line_texture(t_engine *engine, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		get_texture(1, line + i + 2, engine);
		return ;
	}
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		get_texture(2, line + i + 2, engine);
		return ;
	}
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
	{
		get_texture(3, line + i + 2, engine);
		return ;
	}
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
	{
		get_texture(4, line + i + 2, engine);
		return ;
	}
	else if (line[i] == 'S' && line[i + 1] == ' ')
	{
		get_texture(5, line + i + 1, engine);
		return ;
	}
}

static void		line_color(t_engine *engine, char *line, int i)
{
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		get_color(6, line + i + 1, engine);
		return ;
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		get_color(7, line + i + 1, engine);
		return ;
	}
}

static void		dispatch(t_engine *engine, char *line, int i)
{
	if (is_line_texture(line, i) == true)
		line_texture(engine, line, i);
	else if (is_line_floor_ceiling(line, i) == true)
		line_color(engine, line, i);
}

/*
** parsing des lines du fichier .cub
*/

void			check_line(char *line, t_engine *engine)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R' && line[i + 1] == ' ')
		{
			get_resolution(line + i + 1, engine->config);
			return ;
		}
		else if (is_line_texture(line, i) == true
			|| is_line_floor_ceiling(line, i) == true)
		{
			dispatch(engine, line, i);
			return ;
		}
		else if (line[i] == '1')
		{
			get_map(line, engine->config);
			return ;
		}
		i++;
	}
}
