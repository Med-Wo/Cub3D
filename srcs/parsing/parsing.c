/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:57:43 by mravily           #+#    #+#             */
/*   Updated: 2020/03/12 19:22:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	texture_assignment(int id, char *path, t_config *config)
{
	if (id == 1)
		config->north_texture = ft_strdup(path);
	if (id == 2)
		config->south_texture = ft_strdup(path);
	if (id == 3)
		config->west_texture = ft_strdup(path);
	if (id == 4)
		config->east_texture = ft_strdup(path);
	if (id == 5)
		config->sprite_texture = ft_strdup(path);
	if (id == 6)
		config->floor_texture = ft_strdup(path);
	if (id == 7)
		config->ceiling_texture = ft_strdup(path);
}

void 	pre_check_file(int argc, char **argv)
{
	if (argc == 1)
		error_exit(1, "No maps provided");
	else if (argc == 2)
	{
		if (check_argument(1, ".cub", argv[1]) == false)
			error_exit(2, "Invalid map file extension");
	}
	else if (argc == 3)
	{
		if (check_argument(1, ".cub", argv[1]) == false)
			error_exit(3, "Invalid map file extension");
		if (check_argument(0, "-save", argv[2]) == false)
			error_exit(3, "third argument invalid");
		else
			printf("Screenshot Done !!\n");
	}
	else if (argc > 3)
		error_exit(3, "Too many arguments");
}

void 	parsing_cub(char *argv, t_config *config)
{
	int 	fd;
	int 	ret;
	char 	*line;

	fd = open(argv ,O_RDONLY);
	if (fd < 0)
	 	error_exit(1, "Impossible to open the file");
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
			free(line);
		else if (ft_strlen(line) != 0)
			check_line(line, config);
	}
	check_map(config);
}
