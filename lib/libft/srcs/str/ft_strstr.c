/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:58:49 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 12:58:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!find[0])
		return ((char *)&str[i]);
	while (str[i])
	{
		while (find[j] && (str[i + j] == find[j]))
			j++;
		if (!find[j])
			return ((char *)&str[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
