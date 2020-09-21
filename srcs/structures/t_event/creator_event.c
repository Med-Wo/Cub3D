/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 23:44:18 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 16:47:16 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_event		create_event(void)
{
	t_event		result;

	result.start = false;
	result.open_map = false;
	result.run = false;
	result.forward = false;
	result.backward = false;
	result.left = false;
	result.right = false;
	result.rotate_left = true;
	result.rotate_right = false;
	result.shoot_left = false;
	result.shoot_right = false;
	result.fuck = false;
	result.fuck_right = false;
	result.fuck_left = false;
	return (result);
}

t_event		*malloc_event(void)
{
	t_event		*event;

	event = (t_event*)malloc(sizeof(t_event));
	if (event == NULL)
		return (NULL);
	*event = create_event();
	return (event);
}
