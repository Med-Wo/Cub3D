/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:11:37 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:15:47 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function qui free
** - le pointeur de la mlx
** - le pointeur de la fenetre
*/

void	destroy_vars(t_vars to_destroy)
{
	free(to_destroy.mlx_ptr);
	free(to_destroy.win_ptr);
}

/*
** Function qui free la structure vars
*/

void	free_vars(t_vars *to_free)
{
	destroy_vars(*to_free);
	free(to_free);
}
