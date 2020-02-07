/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:12:41 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 21:42:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DATA_H
# define CUB3D_DATA_H

typedef struct  s_data
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}               t_data;

t_data		create_data(void);
t_data		*malloc_data(void);
void		destroy_data(t_data to_destroy);
void		free_data(t_data *to_free);

#endif
