/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_helmet_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 21:42:59 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:24:20 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise en place des path dans un tableau des textures pour le helmet
*/

char			**init_tab_path_helmet_tex(void)
{
	char	**tab_path_helmet;

	tab_path_helmet = (char **)ft_tab_new(HELMET_PART);
	tab_path_helmet[0] = ft_strdup("./textures/xpm/HELMET/HLM_0.xpm");
	tab_path_helmet[1] = ft_strdup("./textures/xpm/HELMET/HLM_1.xpm");
	tab_path_helmet[2] = ft_strdup("./textures/xpm/HELMET/HLM_2.xpm");
	tab_path_helmet[3] = ft_strdup("./textures/xpm/HELMET/HLM_3.xpm");
	tab_path_helmet[4] = ft_strdup("./textures/xpm/HELMET/HLM_4.xpm");
	tab_path_helmet[5] = ft_strdup("./textures/xpm/HELMET/HLM_5.xpm");
	tab_path_helmet[6] = ft_strdup("./textures/xpm/HELMET/HLM_6.xpm");
	tab_path_helmet[7] = ft_strdup("./textures/xpm/HELMET/HLM_7.xpm");
	tab_path_helmet[8] = ft_strdup("./textures/xpm/HELMET/HLM_8.xpm");
	tab_path_helmet[9] = ft_strdup("./textures/xpm/HELMET/HLM_9.xpm");
	tab_path_helmet[10] = ft_strdup("./textures/xpm/HELMET/HLM_10.xpm");
	tab_path_helmet[11] = ft_strdup("./textures/xpm/HELMET/HLM_11.xpm");
	tab_path_helmet[12] = ft_strdup("./textures/xpm/HELMET/HLM_12.xpm");
	tab_path_helmet[13] = ft_strdup("./textures/xpm/HELMET/HUD_TOP.xpm");
	tab_path_helmet[14] = ft_strdup("./textures/xpm/HELMET/HUD_LEFT.xpm");
	tab_path_helmet[15] = ft_strdup("./textures/xpm/HELMET/HUD_RIGHT.xpm");
	tab_path_helmet[16] = ft_strdup("./textures/xpm/ATH/RUN.xpm");
	tab_path_helmet[HELMET_PART] = ft_strdup("\0");
	return (tab_path_helmet);
}

/*
** Initialisation des variables de la struct t_helmet_tex
** - Pointeur vers l'image
** - Les bitmap de l'image stocker en int*
*/

t_helmet_tex	create_helmet_tex(t_engine *engine, char *path)
{
	t_helmet_tex	helmet_tex;

	helmet_tex.path = path;
	helmet_tex.img = NULL;
	helmet_tex.addr = NULL;
	if (!(helmet_tex.img = mlx_xpm_file_to_image(engine->vars->mlx_ptr
		, path, &(helmet_tex.width), &(helmet_tex.height))))
	{
		error_exit_cub(path
		, " During creation xpm pointer for the helmet_tex, path invalid"
		, "Check if the image is present at this path.");
	}
	helmet_tex.addr = mlx_get_data_addr(helmet_tex.img
		, &(helmet_tex.bits_per_pixel)
		, &(helmet_tex.line_length), &(helmet_tex.endian));
	return (helmet_tex);
}

/*
** Mallocage de la structure t_helmet_tex pour le start_screen
*/

t_helmet_tex	*malloc_helmet_tex(t_engine *engine, char *path)
{
	t_helmet_tex	*helmet_tex;

	helmet_tex = (t_helmet_tex *)malloc(sizeof(t_helmet_tex));
	if (helmet_tex == NULL)
		return (NULL);
	*helmet_tex = create_helmet_tex(engine, path);
	return (helmet_tex);
}
