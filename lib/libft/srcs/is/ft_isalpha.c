/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:02 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:28:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (false);
	return (true);
}

bool	ft_strisalpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
