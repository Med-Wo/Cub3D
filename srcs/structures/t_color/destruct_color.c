/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:37:12 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 13:07:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des valeurs de la structure t_color envoyer en parametre
*/

void		destroy_color(t_color to_destroy)
{
	to_destroy.r = 0;
	to_destroy.g = 0;
	to_destroy.b = 0;
}

/*
** Free de la structure t_color envoyer en params
*/

void		free_color(t_color *to_free)
{
	destroy_color(*to_free);
}
