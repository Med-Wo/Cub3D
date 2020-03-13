/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:36:02 by mravily           #+#    #+#             */
/*   Updated: 2020/03/05 19:36:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_len(void	**tab)
{
	int	index;

	index = 0;
	if (tab == NULL)
	{
		return (index);
	}
	while (tab[index] != NULL)
		index++;
	return (index);
}
