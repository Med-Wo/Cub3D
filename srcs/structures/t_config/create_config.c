/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:21:17 by mravily           #+#    #+#             */
/*   Updated: 2020/05/28 12:38:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mallocage de la structure config
*/

t_config		*malloc_config(char *title)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (config == NULL)
		return (NULL);
	*config = create_config(title);
	return (config);
}

static void		init_var(t_config *config)
{
	config->sprite_bonus = false;
	config->save = false;
	config->num_sprites = 0;
	config->floor_color = create_color(0, 0, 0);
	config->ceiling_color = create_color(0, 0, 0);
	config->floor_w = null;
	config->ceiling_w = null;
	config->map = NULL;
	config->len_x = 0;
	config->len_y = 0;
	config->len_pix_x = 0;
	config->len_pix_y = 0;
}

/*
** Initialisation de la structure config aux valeurs par defaults
*/

t_config		create_config(char *title)
{
	t_config	config;
	int			i;

	config.title = ft_strdup(title);
	config.resolution = create_vector(-1, -1);
	i = 0;
	while (i < NB_TEX)
	{
		config.texture[i] = init_texture();
		i++;
	}
	i = 0;
	while (i < NB_SP)
	{
		config.sprite[i] = create_sprite();
		i++;
	}
	init_var(&config);
	return (config);
}
