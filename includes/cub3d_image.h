/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:12:41 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 11:33:16 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_IMAGE_H
# define CUB3D_IMAGE_H

typedef struct	s_image
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef t_image		t_mini_map;
typedef t_image		t_img_welc;
typedef t_image		t_img_hlmt;
typedef t_image		t_img_ath;

t_image			create_image(void);
t_image			*malloc_image(void);
void			destroy_image(t_image to_destroy);
void			free_image(t_image *to_free);

#endif
