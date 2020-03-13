/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:00:44 by mravily           #+#    #+#             */
/*   Updated: 2020/03/06 08:59:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "mlx.h"

# include "cub3d_color.h"
# include "cub3d_drawing.h"
# include "cub3d_appli.h"
# include "cub3d_vector.h"
# include "cub3d_define.h"
# include "cub3d_vars.h"
# include "cub3d_data.h"
# include "cub3d_config.h"
# include "cub3d_parsing.h"
# include "get_next_line.h"
# include "libft.h"

# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)
//# define M_PI 3.141592653589f


void	error_exit(int nb, char *str);




int			close_cub(t_appli *result);
int			deal_key(int key, t_appli *appli);

void		my_mlx_pixel_put(t_appli *appli, int x, int y, t_color color);

bool	ft_strcmp_c(char *p_src, char p_target);

char		*ft_strdup(char *p_src);
void		draw_map(t_appli *appli);
void 		len_map(t_appli *appli, float *len_pixel_x, float *len_pixel_y);
void		move_player_on_map(int key, t_appli *appli);
float		degree_to_radiant(float degree);
void		destroy_n_birth(t_appli *appli);
int			close_cub(t_appli *appli);
void		render(t_appli *appli);
int    		handle_key_release(int key, void *params);
int    		handle_key_pressed(int key, void *params);
void		moove_player(t_appli *appli);

#endif
