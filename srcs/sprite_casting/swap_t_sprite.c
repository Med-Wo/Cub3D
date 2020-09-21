/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_t_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:30:12 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 19:21:01 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function pour swap un structure t_sprite
*/

void			swap_t_sprite(t_sprite *a, t_sprite *b)
{
	t_sprite		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
