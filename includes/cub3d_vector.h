/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:26:56 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 11:13:47 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_VECTOR_H
# define CUB3D_VECTOR_H

# include "cub3d.h"

typedef struct	s_vector
{
	float	x;
	float	y;
}				t_vector;

t_vector		*malloc_vector(float x, float y);
t_vector		create_vector(float x, float y);
void			destroy_vector(t_vector to_destroy);
void			free_vector(t_vector *to_free);
float			calc_distance_vector(t_vector a, t_vector b);

#endif
