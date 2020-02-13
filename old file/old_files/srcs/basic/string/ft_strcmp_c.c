/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 02:58:42 by mravily           #+#    #+#             */
/*   Updated: 2020/01/24 02:59:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_bool	ft_strcmp_c(char *p_src, char p_target)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_target == '\0')
		return (0);
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_target)
			return (true);
		i++;
	}
	return (false);
}
