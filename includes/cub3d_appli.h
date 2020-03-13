/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_appli.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:49 by mravily           #+#    #+#             */
/*   Updated: 2020/03/03 18:53:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_APPLI_H
# define CUB3D_APPLI_H

# include "cub3d_vars.h"
# include "cub3d_data.h"
# include "cub3d_player.h"
# include "cub3d_config.h"
# include "cub3d_event.h"
# include "cub3d_texture.h"

typedef struct 		s_appli
{
	t_vars		*vars;
	t_image		*data;
	t_player	*player;
	t_config	*config;
	t_event 	*event;
	char 		*texture_path;
}					t_appli;

void		init_appli(t_appli *appli);
void		create_appli(t_vars *vars, t_image *data, t_player *player, t_config *config);
t_appli		*malloc_appli(t_vars *vars, t_image *data, t_player *player, t_config *config);
void		destroy_appli(t_appli to_destroy);
void		free_appli(t_appli *to_free);

#endif
