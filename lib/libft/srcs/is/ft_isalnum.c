/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:07 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:28:08 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}

bool	ft_strisalnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
