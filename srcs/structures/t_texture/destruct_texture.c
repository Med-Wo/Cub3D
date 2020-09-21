/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:54:27 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 13:06:29 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des variables de la struct avant free
*/

void	destroy_texture(t_texture to_destroy)
{
	free(to_destroy.path);
	free(to_destroy.img);
	free(to_destroy.color);
}

/*
** Free de la structure envoyer en parametre
*/

void	free_texture(t_texture *to_free)
{
	destroy_texture(*to_free);
}
