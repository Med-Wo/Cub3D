/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:22:29 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 18:19:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_event	*malloc_event(void)
{
	t_event	*event;

	event = (t_event *)malloc(sizeof(t_event));
	if (event == NULL)
		return (NULL);
	*event = create_event();
	return (event);
}

t_event	create_event(void)
{
	t_event	event;

	event.map = false;
	event.test = false;
	event.len_pixel = false;

	return (event);
}

void	destroy_event(t_event to_destroy)
{
	to_destroy.map = 0;
	to_destroy.test = 0;
	to_destroy.len_pixel = 0;
}

void	free_event(t_event *to_free)
{
	destroy_event (*to_free);
	free(to_free);
}
