/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_vars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:06:44 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 11:34:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_VARS_H
# define CUB3D_VARS_H

typedef struct		s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_vars;

t_vars				create_vars(void);
t_vars				*malloc_vars(void);
void				destroy_vars(t_vars to_destroy);
void				free_vars(t_vars *to_free);

#endif
