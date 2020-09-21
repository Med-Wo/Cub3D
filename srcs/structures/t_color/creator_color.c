/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:13:26 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 17:31:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des variables avec les valeurs
** envoyer en parametre de avant mallocage
*/

t_color		create_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}

/*
** Mallocage de la struct qui permets de stocker
** - les couleurs en RGB
*/

t_color		*malloc_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	*color;

	color = (t_color*)malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	*color = create_color(r, g, b);
	return (color);
}
