/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:16:56 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:16:20 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mallocage de la struct qui permets de stocker
** 	- le pointeur de la mlx
** 	- et le pointeur la fenetre
*/

t_vars	*malloc_vars(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	*vars = create_vars();
	return (vars);
}

/*
** Mise a NULL des variables avant mallocage
*/

t_vars	create_vars(void)
{
	t_vars	vars;

	vars.mlx_ptr = NULL;
	vars.win_ptr = NULL;
	return (vars);
}
