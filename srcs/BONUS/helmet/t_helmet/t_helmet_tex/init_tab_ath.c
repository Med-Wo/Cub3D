/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_ath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:24:44 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:30:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise en place des path dans un tableau des textures pour l'ATH
*/

void			init_tab_path_ath_tex_part_3(char **tab_path_ath)
{
	tab_path_ath[21] = ft_strdup("./textures/xpm/ATH/Cmpt_21.xpm");
	tab_path_ath[22] = ft_strdup("./textures/xpm/ATH/Cmpt_22.xpm");
	tab_path_ath[23] = ft_strdup("./textures/xpm/ATH/Cmpt_23.xpm");
	tab_path_ath[24] = ft_strdup("./textures/xpm/ATH/Cmpt_24.xpm");
	tab_path_ath[25] = ft_strdup("./textures/xpm/ATH/Cmpt_25.xpm");
	tab_path_ath[26] = ft_strdup("./textures/xpm/ATH/Health25.xpm");
	tab_path_ath[27] = ft_strdup("./textures/xpm/ATH/Health50.xpm");
	tab_path_ath[28] = ft_strdup("./textures/xpm/ATH/Health75.xpm");
	tab_path_ath[29] = ft_strdup("./textures/xpm/ATH/Health_Full.xpm");
	tab_path_ath[30] = ft_strdup("./textures/xpm/ATH/Armor25.xpm");
	tab_path_ath[31] = ft_strdup("./textures/xpm/ATH/Armor50.xpm");
	tab_path_ath[32] = ft_strdup("./textures/xpm/ATH/Armor75.xpm");
	tab_path_ath[33] = ft_strdup("./textures/xpm/ATH/ArmorFul.xpm");
	tab_path_ath[34] = ft_strdup("./textures/xpm/ATH/ArmorBlu25.xpm");
	tab_path_ath[35] = ft_strdup("./textures/xpm/ATH/ArmorBlu50.xpm");
	tab_path_ath[36] = ft_strdup("./textures/xpm/ATH/ArmorBlu75.xpm");
	tab_path_ath[37] = ft_strdup("./textures/xpm/ATH/Armor_Blue_Ful.xpm");
	tab_path_ath[38] = ft_strdup("./textures/xpm/ATH/Cmpt_50.xpm");
	tab_path_ath[39] = ft_strdup("./textures/xpm/ATH/Cmpt_75.xpm");
	tab_path_ath[40] = ft_strdup("./textures/xpm/ATH/Cmpt_100.xpm");
	tab_path_ath[41] = ft_strdup("./textures/xpm/ATH/Cmpt_125.xpm");
	tab_path_ath[42] = ft_strdup("./textures/xpm/ATH/Cmpt_150.xpm");
	tab_path_ath[43] = ft_strdup("./textures/xpm/ATH/Cmpt_175.xpm");
	tab_path_ath[44] = ft_strdup("./textures/xpm/ATH/Cmpt_200.xpm");
	tab_path_ath[ATH_PART] = ft_strdup("\0");
}

void			init_tab_path_ath_tex_part_2(char **tab_path_ath)
{
	tab_path_ath[11] = ft_strdup("./textures/xpm/ATH/Cmpt_11.xpm");
	tab_path_ath[12] = ft_strdup("./textures/xpm/ATH/Cmpt_12.xpm");
	tab_path_ath[13] = ft_strdup("./textures/xpm/ATH/Cmpt_13.xpm");
	tab_path_ath[14] = ft_strdup("./textures/xpm/ATH/Cmpt_14.xpm");
	tab_path_ath[15] = ft_strdup("./textures/xpm/ATH/Cmpt_15.xpm");
	tab_path_ath[16] = ft_strdup("./textures/xpm/ATH/Cmpt_16.xpm");
	tab_path_ath[17] = ft_strdup("./textures/xpm/ATH/Cmpt_17.xpm");
	tab_path_ath[18] = ft_strdup("./textures/xpm/ATH/Cmpt_18.xpm");
	tab_path_ath[19] = ft_strdup("./textures/xpm/ATH/Cmpt_19.xpm");
	tab_path_ath[20] = ft_strdup("./textures/xpm/ATH/Cmpt_20.xpm");
}

/*
** Mise en place des path dans un tableau des textures pour l'ATH
*/

char			**init_tab_path_ath_tex(void)
{
	char	**tab_path_ath;

	tab_path_ath = (char **)ft_tab_new(ATH_PART);
	tab_path_ath[0] = ft_strdup("./textures/xpm/ATH/Cmpt_0.xpm");
	tab_path_ath[1] = ft_strdup("./textures/xpm/ATH/Cmpt_1.xpm");
	tab_path_ath[2] = ft_strdup("./textures/xpm/ATH/Cmpt_2.xpm");
	tab_path_ath[3] = ft_strdup("./textures/xpm/ATH/Cmpt_3.xpm");
	tab_path_ath[4] = ft_strdup("./textures/xpm/ATH/Cmpt_4.xpm");
	tab_path_ath[5] = ft_strdup("./textures/xpm/ATH/Cmpt_5.xpm");
	tab_path_ath[6] = ft_strdup("./textures/xpm/ATH/Cmpt_6.xpm");
	tab_path_ath[7] = ft_strdup("./textures/xpm/ATH/Cmpt_7.xpm");
	tab_path_ath[8] = ft_strdup("./textures/xpm/ATH/Cmpt_8.xpm");
	tab_path_ath[9] = ft_strdup("./textures/xpm/ATH/Cmpt_9.xpm");
	tab_path_ath[10] = ft_strdup("./textures/xpm/ATH/Cmpt_10.xpm");
	init_tab_path_ath_tex_part_2(tab_path_ath);
	init_tab_path_ath_tex_part_3(tab_path_ath);
	return (tab_path_ath);
}
