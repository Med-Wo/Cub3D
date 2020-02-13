/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:37:12 by mravily           #+#    #+#             */
/*   Updated: 2020/01/23 22:37:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		create_color(uchar_ r, uchar_ g, uchar_ b)
{
	t_color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}

t_color		*malloc_color(uchar_ r, uchar_ g, uchar_ b)
{
	t_color	*color;

	color = (t_color*)malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	*color = create_color(r, g, b);
	return (color);
}

void		destroy_color(t_color to_destroy)
{
	(void)to_destroy;
}

void		free_color(t_color *to_free)
{
	destroy_color(*to_free);
	free(to_free);
}
