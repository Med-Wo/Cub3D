/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:06:42 by mravily           #+#    #+#             */
/*   Updated: 2020/06/14 15:18:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Verification si les color ne sont pas inf a 0 et sup a 255
*/

static void		check_if_rgb(int *rgb, char **tab, char *color)
{
	rgb[0] = ft_atoi(tab[0]);
	if (rgb[0] < 0 && rgb[0] > 255)
		error_exit_cub(color, "Colour red badly formatted"
			, "Find this line in the .cub file");
	rgb[1] = ft_atoi(tab[1]);
	if (rgb[1] < 0 && rgb[1] > 255)
		error_exit_cub(color, "Colour green badly formatted"
			, "Find this line in the .cub file");
	rgb[2] = ft_atoi(tab[2]);
	if (rgb[2] < 0 && rgb[2] > 255)
		error_exit_cub(color, "Colour blue badly formatted"
			, "Find this line in the .cub file");
}

/*
** Verification du formatage color rgb
*/

static void		check_rgb_color(int id, char *color, t_config *config)
{
	char	**tab;
	int		len_tab;
	int		rgb[3];

	tab = NULL;
	len_tab = 0;
	tab = ft_strsplit(color, ',');
	while (tab[len_tab])
		len_tab++;
	if ((len_tab > 3 || len_tab < 3) && id == 0)
		error_exit_cub(color, "Invalid RGB floor color"
			, "Find this line in the .cub file");
	if ((len_tab > 3 || len_tab < 3) && id == 1)
		error_exit_cub(color, "Invalid RGB ceiling color"
			, "Find this line in the .cub file");
	check_if_rgb(rgb, tab, color);
	if (id == 6)
		config->floor_color = create_color(rgb[0], rgb[1], rgb[2]);
	else
		config->ceiling_color = create_color(rgb[0], rgb[1], rgb[2]);
}

/*
** Set de la color du floor ou ceiling
*/

static void		get_rgb(int id, char *line_color, t_config *config)
{
	if (id == 6 && config->floor_w == null)
	{
		config->floor_w = rgb;
		check_rgb_color(id, line_color, config);
	}
	else if (id == 7 && config->ceiling_w == null)
	{
		config->ceiling_w = rgb;
		check_rgb_color(id, line_color, config);
	}
	else
		error_exit_cub(line_color, "Color (floor or ceiling) already attribute"
			, "only one of each element allowed in the .cub file");
}

/*
** Set du path du floor ou ceiling
*/

static void		get_path_color(int id, char *path_color, t_engine *engine)
{
	if (id == 6 && engine->config->floor_w == null)
	{
		engine->config->floor_w = path;
		if (check_texture_path(path_color) == true)
			texture_assignment(id, path_color, engine);
	}
	else if (id == 7 && engine->config->ceiling_w == null)
	{
		engine->config->ceiling_w = path;
		if (check_texture_path(path_color) == true)
			texture_assignment(id, path_color, engine);
	}
	else
		error_exit_cub(path_color, "Path (floor or ceiling) already attribute"
			, "only one of each element allowed in the .cub file");
}

/*
** Recuperation de la couleur en RGB ou path XPM
*/

void			get_color(int id, char *line, t_engine *engine)
{
	char		**tab;
	int			len_tab;
	t_config	*config;

	config = engine->config;
	len_tab = 0;
	tab = NULL;
	tab = ft_strsplit(line, ' ');
	while (tab[len_tab])
		len_tab++;
	printf("len_tab = %d\n", len_tab);
	catch_error_color(id, len_tab, line);
	if (tab[0][0] >= '0' && tab[0][0] <= '9')
		get_rgb(id, tab[0], config);
	else if (tab[0][0] == '.' && tab[0][1] == '/')
		get_path_color(id, tab[0], engine);
}
