/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:28:43 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:18:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_weapon_texture(t_engine *engine, int nb, t_vector coord
	, t_vector size)
{
	size_t				i;
	size_t				j;
	int					fx;
	int					fy;
	t_weapon_tex		weapon;

	weapon = engine->bonus->weapon->weapon[nb];
	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			fx = i / (float)(size.x) * weapon.width;
			fy = j / (float)(size.y) * weapon.height;
			my_mlx_pixel_put_hlmt(engine->bonus->helmet->img_hlmt
				, i + (int)(coord.x), j + (int)(coord.y)
				, hlmt_get_color(&engine->bonus->weapon->weapon[nb], fx, fy));
			j++;
		}
		i++;
	}
}
