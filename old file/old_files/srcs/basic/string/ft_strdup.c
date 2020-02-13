/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:46:16 by mravily           #+#    #+#             */
/*   Updated: 2020/01/30 17:46:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(char *p_src)
{
	int		i;
	int		len;
	char	*dup;

	if (p_src == NULL)
		return (NULL);
	len = ft_strlen(p_src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = p_src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
