/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:20:11 by mravily           #+#    #+#             */
/*   Updated: 2020/02/05 18:18:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EVENT_H
# define CUB3D_EVENT_H

#include "cub3d.h"

enum			e_bool
{
	true = 1,
	false = 0
};

typedef struct 		s_event
{
	enum e_bool 	map;
	enum e_bool 	test;
	enum e_bool 	len_pixel;

}					t_event;

t_event		create_event(void);
t_event		*malloc_event(void);
void		destroy_event(t_event to_destroy);
void		free_event(t_event *to_free);

#endif
