/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:00:49 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:00:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(dst);
	while (src[j] != '\0' && i < (size - 1) && size != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + ft_strlen(dst) - j);
}
