/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 15:18:38 by mravily           #+#    #+#             */
/*   Updated: 2020/06/14 15:18:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			catch_error_color(int id, int len_tab, char *line)
{
	if ((len_tab < 1 || len_tab > 1) && id == 6)
		error_exit_cub(line
			, "Floor line not well formatted"
			, "Find this line in the .cub file");
	if ((len_tab < 1 || len_tab > 1) && id == 7)
		error_exit_cub(line
			, "Ceiling line not well formatted"
			, "Find this line in the .cub file");
	if ((len_tab > 1 || len_tab == 0) && id == 0)
		error_exit_cub(line, "Invalid floor color"
			, "Find this line in the .cub file");
	if ((len_tab > 1 || len_tab == 0) && id == 1)
		error_exit_cub(line, "Invalid ceiling color"
			, "Find this line in the .cub file");
}
