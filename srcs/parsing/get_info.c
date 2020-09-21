/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:46:28 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 15:22:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Recuperation de la resolution et resize en cas de resolution incorrect
*/

void		get_resolution(char *line, t_config *config)
{
	char	**tab;
	int		width;
	int		height;

	tab = NULL;
	tab = ft_strsplit(line, ' ');
	if (ft_tab_len((void**)tab) <= 1)
		error_exit_cub(line, "Resolution line not well formatted"
			, "Find this line in the .cub file");
	width = ft_atoi(tab[0]);
	if (width < 480)
		width = 480;
	if (width > 2560)
		width = 2560;
	height = ft_atoi(tab[1]);
	if (height < 360)
		height = 360;
	if (height > 1440)
		height = 1440;
	if (config->resolution.x == -1 && config->resolution.y == -1)
		config->resolution = create_vector(width, height);
	else
		error_exit_cub(line, "2 lines of resolution in the .cub file"
			, "Find this line in the .cub file");
}

/*
** Verification de la ligne si elle contient uniquement les chars
** autoriser, puis ajout de la line tableau 2D
*/

void		get_map(char *line, t_config *config)
{
	check_line_map(line, config);
	ft_add_to_tab((void *)line, (void ***)&config->map);
}
