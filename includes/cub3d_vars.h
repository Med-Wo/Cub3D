/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_vars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:06:44 by mravily           #+#    #+#             */
/*   Updated: 2020/02/06 17:10:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_VARS_H
# define CUB3D_VARS_H

typedef struct		s_vars
{
    void    *mlx_ptr;
    void    *win_ptr;
}              		t_vars;

extern t_vars		*g_vars;

t_vars		create_vars(void);
t_vars		*malloc_vars(void);
void		destroy_vars(t_vars to_destroy);
void		free_vars(t_vars *to_free);

#endif
