/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:30 by mravily           #+#    #+#             */
/*   Updated: 2020/03/12 18:04:16 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H


void 		pre_check_file(int argc, char **argv);
bool		check_argument(int nb, char *to_check, char *argv);
bool 		check_texture_path(char *path);
void 		check_rgb_color(int id, char *color, t_config *config);
void 		check_line(char *line, t_config *config);
void 		check_color_path(int id, char *line, t_config *config);
void 		check_line_map(char *line, t_config *config);
void 		get_resolution(char *line, t_config *config);
void 		get_texture(int id, char *line, t_config *config);
void 		get_color(int id, char *line, t_config *config);
void		get_map(char *line, t_config *config);
void 		texture_assignment(int id, char *path, t_config *config);
void 		parsing_cub(char *argv, t_config *config);
void 		check_map(t_config *config);
#endif
