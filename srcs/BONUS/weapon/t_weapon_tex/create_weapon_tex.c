/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_weapon_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:49:16 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 15:14:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise en place des path dans un tableau des textures pour le helmet
*/

char				**init_tab_path_weapon_tex(void)
{
	char	**tab_path_weapon;

	tab_path_weapon = (char **)ft_tab_new(WEAPON_PART);
	tab_path_weapon[0] = ft_strdup("./textures/xpm/WEAPON/FUCKA0.xpm");
	tab_path_weapon[1] = ft_strdup("./textures/xpm/WEAPON/FUCKB0.xpm");
	tab_path_weapon[2] = ft_strdup("./textures/xpm/WEAPON/FUCKC1.xpm");
	tab_path_weapon[3] = ft_strdup("./textures/xpm/WEAPON/FUCKD1.xpm");
	tab_path_weapon[4] = ft_strdup("./textures/xpm/WEAPON/FUCKE2.xpm");
	tab_path_weapon[5] = ft_strdup("./textures/xpm/WEAPON/FUCKF2.xpm");
	tab_path_weapon[6] = ft_strdup("./textures/xpm/WEAPON/FUCKG2.xpm");
	tab_path_weapon[7] = ft_strdup("./textures/xpm/WEAPON/FUCKH2.xpm");
	tab_path_weapon[8] = ft_strdup("./textures/xpm/WEAPON/FUCKI2.xpm");
	tab_path_weapon[9] = ft_strdup("./textures/xpm/WEAPON/FIST_0.xpm");
	tab_path_weapon[10] = ft_strdup("./textures/xpm/WEAPON/FIST_RIGHT.xpm");
	tab_path_weapon[11] = ft_strdup("./textures/xpm/WEAPON/FIST_LEFT.xpm");
	tab_path_weapon[12] = ft_strdup("./textures/xpm/WEAPON/DD_0.xpm");
	tab_path_weapon[13] = ft_strdup("./textures/xpm/WEAPON/DD_1.xpm");
	tab_path_weapon[14] = ft_strdup("./textures/xpm/WEAPON/DD_2.xpm");
	tab_path_weapon[15] = ft_strdup("./textures/xpm/WEAPON/DD_3.xpm");
	tab_path_weapon[16] = ft_strdup("./textures/xpm/WEAPON/DD_4.xpm");
	tab_path_weapon[17] = ft_strdup("./textures/xpm/WEAPON/DD_5.xpm");
	tab_path_weapon[18] = ft_strdup("./textures/xpm/WEAPON/DD_6.xpm");
	tab_path_weapon[19] = ft_strdup("./textures/xpm/WEAPON/DD_7.xpm");
	tab_path_weapon[WEAPON_PART] = ft_strdup("\0");
	return (tab_path_weapon);
}

/*
** Initialisation des variables de la struct t_weapon_tex
** - Pointeur vers l'image
** - Les bitmap de l'image stocker en int*
*/

t_weapon_tex		create_weapon_tex(t_engine *engine, char *path)
{
	t_weapon_tex	weapon_tex;

	weapon_tex.path = path;
	weapon_tex.img = NULL;
	weapon_tex.addr = NULL;
	if (!(weapon_tex.img = mlx_xpm_file_to_image(engine->vars->mlx_ptr
		, path, &(weapon_tex.width), &(weapon_tex.height))))
	{
		error_exit_cub(path
		, " During creation xpm pointer for the weapon_tex, path invalid"
		, "Check if the image is present at this path.");
	}
	weapon_tex.addr = mlx_get_data_addr(weapon_tex.img
		, &(weapon_tex.bits_per_pixel)
		, &(weapon_tex.line_length), &(weapon_tex.endian));
	return (weapon_tex);
}

/*
** Mallocage de la structure t_weapon_tex pour le start_screen
*/

t_weapon_tex		*malloc_weapon_tex(t_engine *engine, char *path)
{
	t_weapon_tex	*weapon_tex;

	weapon_tex = (t_weapon_tex *)malloc(sizeof(t_weapon_tex));
	if (weapon_tex == NULL)
		return (NULL);
	*weapon_tex = create_weapon_tex(engine, path);
	return (weapon_tex);
}
