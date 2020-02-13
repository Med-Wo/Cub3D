/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:47:14 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 21:47:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
t_appli *malloc_appli(t_vars *vars, t_data *data, t_player *player, t_config *config)
{
	t_appli	*appli;

	appli = (t_appli *)malloc(sizeof(t_appli));
	if (appli == NULL)
		return (NULL);
	*appli = create_appli(vars, data, player, config);
	return (appli);
}

void	create_appli(t_vars *vars, t_data *data, t_player *player, t_config *config)
{
	t_appli	appli;

	appli.vars = vars;
	appli.data = data;
	appli.player = player;
	appli.config = config;
}
*/

void  destroy_appli(t_appli to_destroy)
{
	free(to_destroy.vars);
	free(to_destroy.data);
	free(to_destroy.player);
	free(to_destroy.config);
	free(to_destroy.event);
	free(to_destroy.texture);
}

void	free_appli(t_appli *to_free)
{
	destroy_appli (*to_free);
	free(to_free);
}
