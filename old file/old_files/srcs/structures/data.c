/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:16:23 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 19:34:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*malloc_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	*data = create_data();
	return (data);
}

t_data	create_data(void)
{
	t_data	data;

	data.title = NULL;
	data.img = NULL;
	data.addr = NULL;
	data.bits_per_pixel = 0;
	data.line_length =  0;
	data.endian = 0;
	return (data);
}

void	destroy_data(t_data to_destroy)
{
	free(to_destroy.img);
	free(to_destroy.addr);
	to_destroy.bits_per_pixel = 0;
	to_destroy.line_length = 0;
	to_destroy.endian = 0;
}

void	free_data(t_data *to_free)
{
	destroy_data (*to_free);
	free(to_free);
}
