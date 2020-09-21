/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_assignment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:05:44 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 10:53:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Verification et assignement du path de texture north et south
*/

static void		assign_north_south(int id, char *path, t_engine *engine)
{
	if (id == 1)
	{
		if (engine->config->texture[NORTH].path == NULL)
			engine->config->texture[NORTH] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path north wall"
			, "Selecting one and deleting the other in the .cub file");
	}
	else if (id == 2)
	{
		if (engine->config->texture[SOUTH].path == NULL)
			engine->config->texture[SOUTH] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path south wall"
			, "Selecting one and deleting the other in the .cub file");
	}
}

/*
** Verification et assignement du path de texture west et east
*/

static void		assign_west_east(int id, char *path, t_engine *engine)
{
	if (id == 3)
	{
		if (engine->config->texture[WEST].path == NULL)
			engine->config->texture[WEST] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path west wall"
			, "Selecting one and deleting the other in the .cub file");
	}
	else if (id == 4)
	{
		if (engine->config->texture[EAST].path == NULL)
			engine->config->texture[EAST] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path east wall"
			, "Selecting one and deleting the other in the .cub file");
	}
}

/*
** Verification et assignement du path de texture floor et ceiling
*/

static void		assign_floor_ceiling(int id, char *path, t_engine *engine)
{
	if (id == 6)
	{
		if (engine->config->texture[FLOOR].path == NULL)
			engine->config->texture[FLOOR] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path floor texture"
			, "Selecting one and deleting the other in the .cub file");
	}
	else if (id == 7)
	{
		if (engine->config->texture[CEILING].path == NULL)
			engine->config->texture[CEILING] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path ceiling texture"
			, "Selecting one and deleting the other in the .cub file");
	}
}

/*
** Assignement des sprites bonus, armes, medkit, shield ect
*/

static void		assign_sprite_bonus(t_engine *engine)
{
	engine->config->texture[BACK_PACK] = create_texture(engine
		, "./textures/xpm/ITEM/BACKPACK.xpm");
	engine->config->texture[LITTLE_MEDKIT] = create_texture(engine
		, "./textures/xpm/ITEM/LITTLE_MEDPACK.xpm");
	engine->config->texture[MEDKIT] = create_texture(engine
		, "./textures/xpm/ITEM/MEDIUM_MEDPACK.xpm");
	engine->config->texture[BLUE_SHIELD] = create_texture(engine
		, "./textures/xpm/ITEM/BLUE_SHIELD.xpm");
	engine->config->texture[GREEN_SHIELD] = create_texture(engine
		, "./textures/xpm/ITEM/GREEN_SHIELD.xpm");
	engine->config->texture[RED_SHIELD] = create_texture(engine
		, "./textures/xpm/ITEM/RED_SHIELD.xpm");
	engine->config->texture[MINI_GUN] = create_texture(engine
		, "./textures/xpm/ITEM/MINI_GUN.xpm");
	engine->config->texture[COCADEMON] = create_texture(engine
		, "./textures/xpm/INFRA1.xpm");
}

void			texture_assignment(int id, char *path, t_engine *engine)
{
	static int i = 0;

	if (id == 1 || id == 2)
		assign_north_south(id, path, engine);
	else if (id == 3 || id == 4)
		assign_west_east(id, path, engine);
	else if (id == 5)
	{
		if (engine->config->texture[SPRITE].path == NULL)
			engine->config->texture[SPRITE] = create_texture(engine, path);
		else
			error_exit_cub(path, "Two path for sprite"
			, "Selecting one and deleting the other in the .cub file");
	}
	else if (id == 6 || id == 7)
		assign_floor_ceiling(id, path, engine);
	else
		error_exit_cub(path, "Unrecognized ID"
			, "Check ID sent in texture assignement");
	if (i == 0)
	{
		assign_sprite_bonus(engine);
		i++;
	}
}
