/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:14 by mravily           #+#    #+#             */
/*   Updated: 2020/03/12 18:00:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_argument(int nb, char *to_check, char *argv)
{
		size_t 	i;
		int		diff;

		i = 0;
		if (nb == 1)
		{
			while (argv[i] != '.')
				i++;
		}
		diff = ft_strcmp(to_check, argv + i);
		if (diff != 0)
			return (false);
		else
			return (true);
}

void 	check_color_path(int id, char *line, t_config *config)
{
	if (check_texture_path(line) == false)
		error_exit(6, "Texture path extension isn't a xpm");
	if (id == 0)
		config->floor_texture = ft_strdup(line);
	else
		config->ceiling_texture = ft_strdup(line);
}

void 	check_line(char *line, t_config *config)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R' && line[i + 1] == ' ')
		{
			get_resolution(line + i + 1, config);
			return;
		}
		else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		{
			get_texture(1, line + i + 2, config);
			return;
		}
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		{
			get_texture(2, line + i + 2, config);
			return;
		}
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		{
			get_texture(3, line + i + 2, config);
			return;
		}
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		{
			get_texture(4, line + i + 2, config);
			return;
		}
		else if (line[i] == 'S' && line[i + 1] == ' ')
		{
			get_texture(5, line + i + 1, config);
			return;
		}
		else if (line[i] == 'F' && line[i + 1] == ' ')
		{
			get_color(0, line + i + 1, config);
			return;
		}
		else if (line[i] == 'C' && line[i + 1] == ' ')
		{
			get_color(1, line + i + 1, config);
			return;
		}
		else if (line[i] == '1')
		{
			get_map(line, config);
			return;
		}
		i++;
	}
}

bool 	check_texture_path(char *path)
{
	size_t 	i;
	int		diff;

	i = 0;
	if (path[0] != '.' && path[1] != '/')
		error_exit(6, "Invalid texture path");
	while (path[i])
			i++;
	diff = ft_strcmp(".xpm", path + i - 4);
	if (diff != 0)
		return (false);
	else
		return (true);
}

void 	check_rgb_color(int id, char *color, t_config *config)
{
	char **tab;
	int 	len_tab;
	int 	rgb[3];

	tab = NULL;
	len_tab = 0;
	tab = ft_strsplit(color, ',');
	while (tab[len_tab])
		len_tab++;
	if ((len_tab > 3 || len_tab < 3) && id == 0)
		error_exit(7, "Invalid RGB floor color");
	if ((len_tab > 3 || len_tab < 3) && id == 1)
		error_exit(7, "Invalid RGB ceiling color");
	rgb[0] = ft_atoi(tab[0]);
	if (rgb[0] < 0 && rgb[0] > 255)
		error_exit(7, "Colour red badly formatted");
	rgb[1] = ft_atoi(tab[1]);
	if (rgb[1] < 0 && rgb[1] > 255)
		error_exit(7, "Colour green badly formatted");
	rgb[2] = ft_atoi(tab[2]);
	if (rgb[2] < 0 && rgb[2] > 255)
		error_exit(7, "Colour blue badly formatted");
	if (id == 0)
		config->floor = create_color(rgb[0], rgb[1], rgb[2]);
	else
		config->ceiling = create_color(rgb[0], rgb[1], rgb[2]);
}
