/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:57:43 by mravily           #+#    #+#             */
/*   Updated: 2020/06/14 14:58:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** verification des arguments entrer lors de l'execution
*/

void			pre_check_file(t_engine *engine, int argc, char **argv)
{
	if (argc == 1)
		error_exit_cub("./Cub3D map.cub", "No maps provided"
			, "Provide a .cub file as argument");
	else if (argc == 2)
	{
		if (check_argument(1, ".cub", argv[1]) == false)
			error_exit_cub(argv[1], "Invalid map file extension"
				, "Only .cub files are accepted");
	}
	else if (argc == 3)
	{
		if (check_argument(1, ".cub", argv[1]) == false)
			error_exit_cub(argv[1], "Invalid map file extension"
				, "Only .cub files are accepted");
		if (check_argument(0, "-save", argv[2]) == false)
			error_exit_cub(argv[2], "third argument invalid"
				, "Only \"-save\" is allowed in third argument");
		else
			engine->config->save = true;
	}
	else if (argc > 3)
		error_exit_cub("", "Too many arguments", "Two argument max");
}

/*
** Verification si tout les textures sont initialisee
** si la position du joueur est indiquer
*/

static void 	check_init_var(t_engine *engine)
{
	if (engine->config->resolution.x == 0)
		error_exit_cub("Resolution", "Resolution not well formatted"
			, "Check .cub file");
	if (engine->config->resolution.y == 0)
		error_exit_cub("Resolution", "Resolution not well formatted"
			, "Check .cub file");
	if (engine->player->pos.x == 0)
		error_exit_cub("player->pos", "Player position not indicated in map"
			, "Check .cub file");
	if (engine->player->pos.y == 0)
		error_exit_cub("player->pos", "Player position not indicated in map"
			, "Check .cub file");
	if (engine->config->texture[NORTH].path == NULL)
		error_exit_cub("Texture[NORTH]", "Provided path texture"
			, "Check .cub file");
	if (engine->config->texture[SOUTH].path == NULL)
		error_exit_cub("Texture[SOUTH]", "Provided path texture"
			, "Check .cub file");
	if (engine->config->texture[WEST].path == NULL)
		error_exit_cub("Texture[WEST]", "Provided path texture"
			, "Check .cub file");
	if (engine->config->texture[EAST].path == NULL)
		error_exit_cub("Texture[EAST]", "Provided path texture"
			, "Check .cub file");
	if (engine->config->texture[SPRITE].path == NULL)
		error_exit_cub("Texture[SPRITE]", "Provided path texture"
			, "Check .cub file");
	if (engine->config->ceiling_w == null)
		error_exit_cub("Texture[NORTH]"
			, "Provided path rgb color or path ceiling"
			, "Check .cub file");
	if (engine->config->floor_w == null)
		error_exit_cub("Texture[NORTH]"
			, "Provided path rgb color or path ceiling"
			, "Check .cub file");

}

/*
** parsing des information du fichier .cub
*/

void			parsing_cub(char *argv, t_engine *engine)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit_cub("", "Impossible to open the file", "Check path file");
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
			free(line);
		else if (ft_strlen(line) != 0)
			check_line(line, engine);
	}
	check_map(engine->config, engine->player);
	check_init_var(engine);
}
