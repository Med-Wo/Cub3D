/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:08:30 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 12:23:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** verification que la line ne comporte que les char autorisé
** et recuperation de la taille de la plus grande line
*/

void			check_line_map(char *line, t_config *config)
{
	size_t		i;

	i = 0;
	while (ft_strcmp_c(" 0123456789NSWE", line[i]) == true)
		i++;
	if (line[i] != '\0')
		error_exit_cub(line, "Invalid character in the map"
			, "Find this line in the .cub file");
	else if (i > config->len_x)
		config->len_x = i;
}

/*
** verification autour du point donner, que aucun espace ne ce trouve
*/

void			check_around(char **map, t_vector index)
{
	if (index.x == 0)
		error_exit_cub(map[(int)index.y], "Invalid map"
			, "Find this line in the .cub file");
	if (map[(int)index.y - 1][(int)index.x] == ' ')
		error_exit_cub(map[(int)index.y], "Invalid map"
			, "Find this line in the .cub file");
	if (map[(int)index.y][(int)index.x - 1] == ' ')
		error_exit_cub(map[(int)index.y], "Invalid map"
			, "Find this line in the .cub file");
	if (map[(int)index.y + 1][(int)index.x] == ' '
	|| map[(int)index.y + 1] == NULL)
		error_exit_cub(map[(int)index.y], "Invalid map"
			, "Find this line in the .cub file");
	if (map[(int)index.y][(int)index.x + 1] == ' '
		|| map[(int)index.y][(int)index.x + 1] == '\0')
		error_exit_cub(map[(int)index.y], "Invalid map"
			, "Find this line in the .cub file");
}

/*
** Verification si la 1er ligne de la map ne contient que des 1
*/

static float	check_first_line_map(char **map, t_vector index)
{
	if (map[(int)index.y][(int)index.x] != '1')
		index.x++;
	if (map[(int)index.y][(int)index.x] == '1')
	{
		while (ft_strcmp_c("1", map[(int)index.y]
			[(int)index.x]) == true)
			index.x++;
		if (map[(int)index.y][(int)index.x] != '\0')
			error_exit_cub(map[(int)index.y], "Invalid map"
				, "Find this line in the .cub file");
	}
	return (index.x);
}

/*
** Verification des autres lignes de la map et set du players et sprites
*/

static float	check_other_map_line(t_config *config, t_player *player
	, char **map, t_vector index)
{
	if (map[(int)index.y][(int)index.x] == '0')
	{
		check_around(map, index);
		index.x++;
	}
	else if (is_sprite(map, index, "23456789") == true)
	{
		check_and_set_sprite(config, map, index);
		index.x++;
	}
	else if (is_cardi_point(index, map) == true)
	{
		set_player(map, index, player);
		index.x++;
	}
	else
		index.x++;
	return (index.x);
}

/*
** verification que la map soit bien formater,
** qu'il n'y ai aucun espace vide ou le joueur pourrais sortir
*/

void			check_map(t_config *config, t_player *player)
{
	char		**map;
	t_vector	index;

	map = config->map;
	index.y = 0;
	while (map[(int)index.y])
	{
		index.x = 0;
		while (map[(int)index.y][(int)index.x])
		{
			if (index.y == 0)
				index.x = check_first_line_map(map, index);
			else
				index.x = check_other_map_line(config, player, map, index);
		}
		index.y++;
		if (index.y > config->len_y)
			config->len_y = index.y;
	}
}
