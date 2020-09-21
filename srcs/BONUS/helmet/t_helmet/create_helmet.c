/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_helmet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:35:36 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:35:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des elements de la structure t_helmet
*/

t_helmet		create_helmet(t_engine *engine)
{
	t_helmet		result;
	int				i;
	char			**path_helmet;

	path_helmet = init_tab_path_helmet_tex();
	i = 0;
	while (i < HELMET_PART)
	{
		result.helmet_part[i] = create_helmet_tex(engine, path_helmet[i]);
		i++;
	}
	ft_tab_free(path_helmet);
	path_helmet = init_tab_path_ath_tex();
	i = 0;
	while (i < ATH_PART)
	{
		result.ath_part[i] = create_helmet_tex(engine, path_helmet[i]);
		i++;
	}
	ft_tab_free(path_helmet);
	result.id_part_helmet = 0;
	result.put_helmet = 0;
	result.img_hlmt = malloc_img_hlmt(engine, engine->config->resolution.x
		, engine->config->resolution.y);
	return (result);
}

t_helmet		*malloc_helmet(t_engine *engine)
{
	t_helmet	*helmet;

	helmet = (t_helmet *)malloc(sizeof(t_helmet));
	if (helmet == NULL)
		return (NULL);
	*helmet = create_helmet(engine);
	return (helmet);
}
