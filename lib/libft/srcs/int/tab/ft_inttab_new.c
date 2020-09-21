/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:12 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:28:13 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_inttab_new(int size)
{
	int	i;
	int	**result;

	result = (int **)malloc(sizeof(int *) * (size + 1));
	if (result == NULL)
		error_exit("", "Can't malloc a int **");
	i = 0;
	while (i < size + 1)
	{
		result[i] = NULL;
		i++;
	}
	return (result);
}
