/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_drawing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:29:26 by mravily           #+#    #+#             */
/*   Updated: 2020/03/04 16:46:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DRAWING_H
# define CUB_DRAWING_H

# include "cub3d_appli.h"
# include "cub3d_vector.h"
# include "cub3d_color.h"
# include "cub3d.h"

void	draw_rectangle(t_appli *appli, t_vector coord, t_vector size, t_color color);
void	draw_circle(t_appli *appli, t_vector coord, int radius, t_color color);
void	draw_line (t_appli *appli, t_vector start, t_vector end, t_color color);
void    my_mlx_pixel_put(t_appli *appli, int x, int y, t_color color);
void	draw_texture(t_appli *appli, t_texture *texture, t_vector coord, t_vector size);

#endif
