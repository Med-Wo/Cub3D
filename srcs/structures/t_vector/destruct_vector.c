/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:25:39 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 13:04:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des elements de la structure
*/

void		destroy_vector(t_vector to_destroy)
{
	to_destroy.x = 0;
	to_destroy.y = 0;
}

/*
** Free de la structure t_vector
*/

void		free_vector(t_vector *to_free)
{
	destroy_vector(*to_free);
}
