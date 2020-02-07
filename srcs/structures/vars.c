/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:09:41 by mravily           #+#    #+#             */
/*   Updated: 2020/02/06 17:13:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vars	*g_vars;

t_vars	*malloc_vars(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	*vars = create_vars();
	g_vars = vars;
	return (vars);
}

t_vars	create_vars(void)
{
	t_vars	vars;

	vars.mlx_ptr = NULL;
	vars.win_ptr = NULL;
	return (vars);
}

void	destroy_vars(t_vars to_destroy)
{
	free(to_destroy.mlx_ptr);
	free(to_destroy.win_ptr);
}

void	free_vars(t_vars *to_free)
{
	destroy_vars (*to_free);
	free(to_free);
}
