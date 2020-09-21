/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:48:24 by mravily           #+#    #+#             */
/*   Updated: 2020/03/28 17:50:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_exit(char *line, char *str)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[\"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\"]", 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}
