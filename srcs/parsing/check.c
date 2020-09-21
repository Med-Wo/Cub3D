/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:14 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 13:43:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		check_argument(int nb, char *to_check, char *argv)
{
	size_t	i;
	int		diff;

	i = 0;
	if (nb == 1)
	{
		while (argv[i] != '.')
			i++;
	}
	diff = ft_strcmp(to_check, argv + i);
	if (diff != 0)
		return (false);
	else
		return (true);
}

/*
** Verication du formatage des path de textures
*/

bool		check_texture_path(char *path)
{
	size_t	i;
	int		diff;

	i = 0;
	if (path[0] != '.' && path[1] != '/')
		error_exit_cub(path, "Invalid texture path"
			, "Find this line in the .cub file");
	while (path[i])
		i++;
	diff = ft_strcmp(".xpm", path + i - 4);
	if (diff != 0)
		return (false);
	else
		return (true);
}
