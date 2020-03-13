/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:20:11 by mravily           #+#    #+#             */
/*   Updated: 2020/03/04 19:53:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EVENT_H
# define CUB3D_EVENT_H

#include <stdbool.h>

typedef struct 		s_event
{
	bool 	map;
	bool 	test;
	bool 	len_pixel;

}					t_event;

t_event		create_event(void);
t_event		*malloc_event(void);
void		destroy_event(t_event to_destroy);
void		free_event(t_event *to_free);

#endif
