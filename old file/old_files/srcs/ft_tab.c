/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:01:31 by mravily           #+#    #+#             */
/*   Updated: 2020/01/30 17:36:38 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_tab_len(char **tab)
{
	int		i;
	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char		**ft_tab_new(int len)
{
	int	i;
	char	**result;
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = NULL;
		i++;
	}
	return(result);
}

char		**ft_tabdup(char **tab)
{
	int		i;
	int		len;
	char	**result;
	len = ft_tab_len(tab);
	printf("|%d|\n", len);
	result = ft_tab_new(len);
	i = 0;
	while (tab[i] != NULL)
	{
		result[i] = ft_strdup(tab[i]);
		i++;
	}
	return (result);
}
