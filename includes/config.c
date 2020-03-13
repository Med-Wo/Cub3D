/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:42:05 by mravily           #+#    #+#             */
/*   Updated: 2020/01/31 13:45:49 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_config	*malloc_config(char *title)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (config == NULL)
		return (NULL);
	*config = create_config(title);
	return (config);
}

t_config	create_config(char *title)
{
	t_config	config;

	config.title = title;
	config.resolution_size = create_vector(0, 0);
	config.north_texture = NULL;
	config.south_texture = NULL;
	config.west_texture = NULL;
	config.east_texture = NULL;
	config.sprite_texture = NULL;
	config.floor = create_color(0, 0, 0);

	config.ceiling = create_color(0, 0 ,0);
	config.map = NULL;
	return (config);
}

void	free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

void	destroy_config(t_config to_destroy)
{
	free(to_destroy.title);
	free(to_destroy.north_texture);
	free(to_destroy.south_texture);
	free(to_destroy.west_texture);
	free(to_destroy.east_texture);
	free(to_destroy.sprite_texture);
	free_color(&to_destroy.floor);
	free_color(&to_destroy.ceiling);
	free_map(to_destroy.map);
}

void	free_config(t_config *to_free)
{
	destroy_config (*to_free);
	free(to_free);
}
