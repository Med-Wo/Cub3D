/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:58:51 by mravily           #+#    #+#             */
/*   Updated: 2020/01/23 17:58:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_COLOR_H
# define CUB3D_COLOR_H

typedef unsigned char uchar_;

typedef struct	s_color
{
	uchar_	r;
	uchar_	g;
	uchar_	b;
}				t_color;

t_color		*malloc_color(uchar_ r, uchar_ g, uchar_ b);
t_color		create_color(uchar_ r, uchar_ g, uchar_ b);
void		destroy_color(t_color to_destroy);
void		free_color(t_color *to_free);
int			convert_color(t_color color);

#endif