/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:46:28 by mravily           #+#    #+#             */
/*   Updated: 2020/03/12 19:23:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	get_color(int id, char *line, t_config *config)
{
	char 	**tab;
	int 	len_tab;

	len_tab = 0;
	tab = NULL;
	tab = ft_strsplit(line, ' ');
	while (tab[len_tab])
		len_tab++;
	if ((len_tab > 1 || len_tab == 0) && id == 0)
		error_exit(7, "Invalid floor color");
	if ((len_tab > 1 || len_tab == 0) && id == 1)
		error_exit(7, "Invalid ceiling color");
	if (tab[0][0] >= '0' && tab[0][0] <= '9')
		check_rgb_color(id, tab[0], config);
	else if (tab[0][0] == '.' && tab[0][1] == '/')
		check_color_path(id, tab[0], config);
}

void 	get_resolution(char *line, t_config *config)
{
	char 	**tab;
	int 	width;
	int 	height;

	tab = NULL;
	tab = ft_strsplit(line, ' ');
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
	config->resolution = create_vector(width, height);

}

void 	check_line_map(char *line, t_config *config)
{
	int		i;

	i = 0;
	//printf("line = %s\n", line);
	while (ft_strcmp_c(" 012NSWE", line[i]) == true)
		i++;
	if (line[i] != '\0')
		error_exit(8, "Invalid character in the map");
	else if (i > config->len_x)
		config->len_x = i;
}

void 	check_map(t_config *config)
{
	char 		**map;
	size_t 		i;
	size_t 		j;
	int check = 0;

	map = config->map;
	//ft_print_str_tab("tab", map);
	i = 0;
	while (map[i])
	{
		j = 0;
		//printf("i = %zu\n", i);
		while (map[i][j])
		{
			if (i == 0)
			{
				if (map[i][j] != '1')
					j++;
				if (map[i][j] == '1')
				{
					//printf("1_map[%zu][%zu]\n", i, j);
					while(ft_strcmp_c("1", map[i][j]) == true)
						j++;
					if (map[i][j] != '\0')
						error_exit(9, "Invalid map");
				}
			}
			
			else if (map[i][j] == '0' || map[i][j] == '2')
			{
				if (j == 0)
					error_exit(9, "Invalid map");
				if (map[i - 1][j] == ' ')
					error_exit(9, "Invalid map");
				if (map[i - 1][j - 1] == ' ')
					error_exit(9, "Invalid map");
				if (map[i][j - 1] == ' ')
					error_exit(9, "Invalid map");
				if (map[i + 1][j - 1] == ' ' && map[i + 1] == NULL && j == 0)
					error_exit(9, "Invalid map");
				if (map[i + 1][j] == ' ' && map[i + 1] == NULL)
					error_exit(9, "Invalid map");
				if (map[i + 1][j + 1] == ' ' || map[i] == NULL || map[i + 1][j + 1] == '\0')
					error_exit(9, "Invalid map");
				if (map[i][j + 1] == ' ' || map[i][j + 1] == '\0')
					error_exit(9, "Invalid map");
				if (map[i - 1][j + 1] == ' ' || map[i][j + 1] == '\0')
					error_exit(9, "Invalid map");
				j++;
			}
			else
				j++;
			//printf("1_map[%zu][%zu]\n", i, j);
		}
		i++;
	}
	//printf("2_i = %zu\n", i);
}

void	get_map(char *line, t_config *config)
{
	check_line_map(line, config);
	ft_add_to_tab((void *)line, (void ***)&config->map);
	//check_map(config);
}

void 	get_texture(int id, char *line, t_config *config)
{
		char 	**tab;
		int 	len_tab;

		(void)config;

		tab = NULL;
		len_tab = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[len_tab])
			len_tab++;
		if (len_tab > 1 || len_tab == 0)
			error_exit(5, "Invalid texture path");
		if (check_texture_path(tab[0]) == false)
			error_exit(6, "Texture path extension isn't a xpm");
		texture_assignment(id, tab[0], config);
}
