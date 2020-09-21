/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:56:36 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 12:56:38 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_leaks(char *prog_name, char *msg)
{
	char	*command;
	char	*tmp;

	tmp = ft_strdup("leaks ");
	command = ft_strjoin(tmp, prog_name);
	free(tmp);
	tmp = command;
	command = ft_strjoin(tmp, " | grep 'total leaked bytes'");
	free(tmp);
	system(command);
	ft_putstr(msg);
	ft_putchar('\n');
	ft_putchar('\n');
	free(command);
}
