/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 22:57:32 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:13:45 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des elements de la structure
*/

t_vector	create_vector(float x, float y)
{
	t_vector result;

	result.x = x;
	result.y = y;
	return (result);
}

/*
** Mallocage de la structure
*/

t_vector	*malloc_vector(float x, float y)
{
	t_vector *result;

	result = (t_vector *)malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	*result = create_vector(x, y);
	return (result);
}
