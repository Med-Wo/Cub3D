/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:30 by mravily           #+#    #+#             */
/*   Updated: 2020/06/14 15:17:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include "cub3d_engine.h"
# include "cub3d_config.h"
# include "cub3d_player.h"
# include "cub3d_image.h"
# include "cub3d_ray_cast.h"
# include "cub3d_texture.h"

bool		check_argument(int nb, char *to_check, char *argv);
bool		check_texture_path(char *path);
void		check_line(char *line, t_engine *engine);
void		check_line_map(char *line, t_config *config);
void		get_resolution(char *line, t_config *config);
void		get_texture(int id, char *line, t_engine *engine);
void		get_color(int id, char *line, t_engine *engine);
void		get_map(char *line, t_config *config);
void		texture_assignment(int id, char *path, t_engine *engine);
void		generate_texture(t_texture *texture, t_image *image);
void		parsing_cub(char *argv, t_engine *engine);
void		check_map(t_config *config, t_player *player);
bool		is_wall(char **map, t_vector index);
bool		is_space(t_vector index, char **map);
bool		is_sprite(char **map, t_vector index, char *list_sprite);
void		check_around(char **map, t_vector index);
void		check_and_set_sprite(t_config *config, char **map, t_vector index);
void		set_player(char **map, t_vector index, t_player *player);
bool		is_med_kit(char **map, t_vector index);
bool		is_back_pack(char **map, t_vector index);
bool		is_shield(char **map, t_vector index);
bool		is_line_floor_ceiling(char *line, int i);
bool		is_line_texture(char *line, int i);
void		catch_error_color(int id, int len_tab, char *line);
#endif
