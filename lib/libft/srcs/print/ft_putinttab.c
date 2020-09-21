/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:03:10 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:03:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab(int **tab, int len)
{
	int	j;
	int	i;

	if (tab == NULL)
		error_exit("", "No int tab to print");
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (j < len)
		{
			if (j != 0)
				ft_putstr("\t");
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
